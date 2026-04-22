*This project has been created as part of the 42 curriculum by mmelo, stehoffm.*

<h1 align="center">push_swap</h1>

## Description

`push_swap` is a constrained sorting project: the program receives an unsorted sequence of integers in **stack A**, starts with an empty **stack B**, and must output a valid sequence of stack operations that sorts the data in ascending order using as few moves as possible.

This implementation does not rely on a single universal strategy. Instead, it embeds **multiple sorting approaches** and exposes them through command-line flags:

- `--simple` → baseline **O(n²)** strategy
- `--medium` → chunk/range-based **O(n√n)** strategy
- `--complex` → binary radix **O(n log n)** strategy
- `--adaptive` → automatic selector
- `--bench` → prints diagnostic metrics to `stderr`

The project is built around three core ideas:

1. **Normalize values into ranks** so algorithms can work on dense indices instead of raw integers.
2. **Measure disorder** before sorting, so the input can be inspected rather than treated blindly.
3. **Select a strategy intentionally** instead of forcing one algorithm on every input size.

## Project split

This project was developed collaboratively, with both learners understanding and contributing to the final result.

### stehoffm

- most of the parsing pipeline
- input validation logic
- index assignment / normalization logic
- `push`, `rotate`, and related core operation work
- **simple** sorting strategy: min extraction
- **medium** sorting strategy: range / chunk sort
- many helper functions for stack creation and stack utilities

### mmelo

- **complex** sorting strategy: radix-based sort
- benchmark input / diagnostic mode
- worked together on parts of input validation
- low-disorder / small-size helper path
- disorder metric
- adaptive strategy logic

## Project goal

The real challenge of `push_swap` is not merely sorting. It is sorting **under constraints**:

- only two stacks are available,
- only a small instruction set may be used,
- every move matters,
- and the output is not the sorted array itself, but the **program** that produces it.

That changes the problem from classic sorting into **algorithm design in an operation-cost model**.

## Instructions

### Compilation

```bash
make
```

### Basic usage

```bash
./push_swap 3 2 1
```

### Force a specific strategy

```bash
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
```

### Run with benchmark output

```bash
./push_swap --bench 4 67 3 87 23
./push_swap --bench --complex 4 67 3 87 23
./push_swap --adaptive --bench 4 67 3 87 23
```

### Verify with a checker

```bash
ARG="4 67 3 87 23"
./push_swap --complex $ARG | ./checker_linux $ARG
```

### Rebuild from scratch

```bash
make re
```

## Command-line interface

<table>
  <thead>
    <tr>
      <th>Flag</th>
      <th>Meaning</th>
      <th>Notes</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>--simple</code></td>
      <td>Forces the simple strategy</td>
      <td>Selection/min-extraction style approach</td>
    </tr>
    <tr>
      <td><code>--medium</code></td>
      <td>Forces the medium strategy</td>
      <td>Chunk / range-based pushing</td>
    </tr>
    <tr>
      <td><code>--complex</code></td>
      <td>Forces the complex strategy</td>
      <td>Binary radix on indexed values</td>
    </tr>
    <tr>
      <td><code>--adaptive</code></td>
      <td>Automatic strategy selection</td>
      <td>Default mode when no strategy flag is passed</td>
    </tr>
    <tr>
      <td><code>--bench</code></td>
      <td>Prints metrics to <code>stderr</code></td>
      <td>Can be combined with one strategy selector</td>
    </tr>
  </tbody>
</table>

### Flag rules

- At most **one strategy selector** may be used.
- `--bench` may be combined with exactly one strategy selector.
- The order of `--bench` and the strategy flag is accepted in either direction.
- Invalid flag combinations print `Error` to `stderr`.

## Allowed operations


  <code>sa</code> <code>sb</code> <code>ss</code>
  <code>pa</code> <code>pb</code>
  <code>ra</code> <code>rb</code> <code>rr</code>
  <code>rra</code> <code>rrb</code> <code>rrr</code>



  <summary><strong>Operation meaning</strong></summary>


- **swap**: exchange the top two nodes of a stack
- **push**: move the top node from one stack to the other
- **rotate**: move the first node to the back
- **reverse rotate**: move the last node to the front

</details>

## Internal representation

The stacks are implemented as a **singly linked list**:

```c
typedef struct s_stack
{
    int             num;
    int             index;
    struct s_stack  *next;
}   t_stack;
```

Each node stores:

- `num` → the original integer value
- `index` → the normalized rank of that value in the full dataset

### Why indexing matters

Sorting raw integers directly is awkward when values are large, negative, or sparse. By assigning each value a rank from `0` to `n - 1`, the algorithms can reason about relative order, chunk windows, and bit positions without caring about the original numeric magnitude.

## Input pipeline

The program validates and transforms input in distinct steps:

1. **Lexical validation**  
   Each token must be non-empty, may begin with `+` or `-`, and must otherwise contain only digits.

2. **Integer conversion with overflow protection**  
   Values are parsed manually into a `long` and rejected if they exceed signed 32-bit integer limits.

3. **Stack construction**  
   Validated integers are appended to stack A.

4. **Duplicate detection**  
   Repeated values abort the program with an error.

5. **Index assignment**  
   Each node receives a rank equal to the number of values smaller than it.

## Disorder metric

A key feature of this project is the computation of a **disorder score** before sorting.

### Definition

The metric counts pairwise inversions:

- compare each node with all nodes after it,
- count pairs that are out of ascending order,
- divide by the total number of pairs.

So the metric lies in the interval:

```text
0.0 = already sorted
1.0 = maximally reversed
```

### Interpretation

- **Low disorder** means many elements are already near their correct relative order.
- **High disorder** means the input behaves more like a random or reversed permutation.

## Algorithms

<table>
  <thead>
    <tr>
      <th>Strategy</th>
      <th>Implementation</th>
      <th>Main idea</th>
      <th>Claimed class</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>--simple</code></td>
      <td><code>min_extraction()</code></td>
      <td>Repeatedly extract the next minimum rank</td>
      <td><code>O(n²)</code></td>
    </tr>
    <tr>
      <td><code>--medium</code></td>
      <td><code>range_sort()</code></td>
      <td>Push rank windows to B, then rebuild from max to min</td>
      <td><code>O(n√n)</code></td>
    </tr>
    <tr>
      <td><code>--complex</code></td>
      <td><code>radix()</code></td>
      <td>Binary LSD radix over normalized ranks</td>
      <td><code>O(n log n)</code></td>
    </tr>
    <tr>
      <td><code>small-case helper</code></td>
      <td><code>bad_sort()</code></td>
      <td>Local repair path for tiny inputs</td>
      <td>special-case path</td>
    </tr>
  </tbody>
</table>

## Resources

<a href="https://www.geeksforgeeks.org/dsa/sorting-algorithms/"> geeksforgeeks.org / sorting algorithms </a>\
<a href="https://en.wikipedia.org/wiki/Stack_(abstract_data_type)"> wikipedia.org / Stack </a>\
<a href="https://en.wikipedia.org/wiki/Radix_sort"> wikipedia.org / Radix sort</a>\
<a href="https://en.wikipedia.org/wiki/Bitwise_operations_in_C"> wikipedia.org / Bitwise operations in C </a>

### AI usage

Replace this subsection with your actual usage.

- AI was used for discussion, review, and explanation support.
- AI was not used as a substitute for understanding or peer review.
- Final code and algorithm choices were reviewed manually.

### Documentation
- [ ] 42 subject / project PDF
- [ ] Stack and linked list references
- [ ] Sorting algorithm references
- [ ] Bitwise/radix references

### Articles / tutorials
- [ ] Chunk-based sorting notes
- [ ] Inversion counting / disorder metrics
- [ ] Complexity analysis references

## Detailed explanation and justification

### Simple strategy — <code>min_extraction()</code></strong></summary>

This strategy behaves like a stack-adapted **selection sort**.

For each target rank:

1. find its position in A,
2. rotate in the cheaper direction,
3. `pb` it to B,
4. continue until only the final remainder stays in A,
5. `pa` everything back.

It is **O(n²)** because repeated search and rotation are performed across the full input. Its main value is simplicity, predictability, and good behavior on small datasets.


### Medium strategy — <code>range_sort()</code></strong></summary>

This strategy is a **chunk / range-based sorter**.

The range size is chosen as:

```text
ceil(sqrt(n))
```

#### Phase A → B

While A is not empty:

- if top rank `<= current_rank`, push to B and rotate B,
- else if top rank `<= current_rank + range_size`, push to B,
- else rotate A.

This keeps smaller values deeper in B and larger values closer to the top.

#### Phase B → A

- find the maximum rank in B,
- move it to the top with `rb` or `rrb`,
- `pa` it back to A,
- repeat until B is empty.

This is the project’s middle-ground strategy: more structured than repeated extraction, but easier to reason about than radix.



### Complex strategy — <code>radix()</code></strong></summary>

This is a **binary LSD radix sort** on the normalized `index` field.

For each bit position:

1. inspect the current top index,
2. if the bit is `1`, rotate A,
3. if the bit is `0`, push to B,
4. after one pass, push everything back from B to A,
5. continue with the next bit.

Because the number of meaningful bits grows with `log₂(n)` and each pass touches every element once, this gives the project’s most scalable strategy: **O(n log n)**.




### Small-case helper — <code>bad_sort()</code></strong></summary>

Despite the name, this routine acts as a targeted fixer for very small inputs. For tiny stacks, constant factors matter more than asymptotic elegance, so a short local repair path is practical.



### Adaptive strategy

The project computes disorder before sorting and includes an adaptive selector.

In the **current implementation**, the final choice is mainly driven by **input size**:

```text
size <= 3      -> bad_sort
size <= 5      -> simple
size <= 1100   -> medium
else           -> complex
```

### Practical consequence

At the moment, adaptive mode behaves primarily as a **size-based selector**, while still keeping disorder available for diagnostics and future refinement.

## Benchmark output

When `--bench` is enabled, the program prints diagnostic information to `stderr`:

- disorder percentage,
- selected strategy,
- reported theoretical complexity class,
- total operation count,
- per-operation counters.

Example:

```text
[bench] disorder: 62.50%
[bench] strategy: Adaptive / O(n sqrt(n))
[bench] total_ops: 731
[bench] sa: 0 sb: 0 ss: 0 pa: 100 pb: 100
[bench] ra: 290 rb: 52 rr: 0 rra: 101 rrb: 88 rrr: 0
```

## Project structure

```text
push_swap/
├── Makefile
├── push_swap.h
├── stack.h
├── operations.h
├── helpers.h
├── main.c
├── push_swap.c
├── parser.c
├── data_validation.c
├── disorder.c
├── index_stack.c
├── stack_creation_utils.c
├── helpers.c
├── push_sort.c
├── swap_sort.c
├── rotate_sort.c
├── rev_rotate_sort.c
├── simple_algo.c
├── medium_algo.c
├── medium_algo_helper.c
├── complex_algo.c
├── low_disorder_algo.c
├── adaptive_algo.c
├── benchmark.c
└── libft/
```

### File responsibilities

- **main.c** → flag parsing and dispatch
- **push_swap.c** → pipeline orchestration and strategy execution
- **parser.c** → safe integer parsing
- **data_validation.c** → lexical validation and duplicate detection
- **disorder.c** → inversion-density metric
- **index_stack.c** → rank assignment
- **stack_creation_utils.c** → linked-list utilities
- **push / swap / rotate / reverse rotate files** → primitive operations
- **simple_algo.c** → O(n²) strategy
- **medium_algo.c + medium_algo_helper.c** → O(n√n) strategy
- **complex_algo.c** → O(n log n) radix strategy
- **low_disorder_algo.c** → small-input helper
- **benchmark.c** → diagnostic output

## Technical choices

### Linked lists instead of arrays

Using linked nodes keeps stack operations natural:

- pushing to the front is cheap,
- top-of-stack mutation is direct,
- operations map closely to the stack model.

### Rank normalization

This enables both chunking and radix logic to stay simple and consistent.

### Manual integer parsing

Overflow is handled explicitly rather than delegated to platform-dependent behavior.

### Operation accounting

Every primitive increments counters that can later be summarized in benchmark mode.

## Error handling

The program prints:

```text
Error
```

to `stderr` when it encounters invalid input, such as:

- non-integer tokens,
- empty arguments,
- sign-only arguments like `+` or `-`,
- integer overflow / underflow outside 32-bit range,
- duplicate values,
- invalid flag combinations.

If no numbers are provided, the program exits silently.

## Example workflow

```bash
# Build
make

# Run default mode
./push_swap 8 5 6 3 1 2

# Compare strategies
ARG="8 5 6 3 1 2 7 4"
./push_swap --simple $ARG | wc -l
./push_swap --medium $ARG | wc -l
./push_swap --complex $ARG | wc -l

# Inspect metrics
./push_swap --bench --adaptive $ARG > /dev/null
```
