*This project has been created as part of the 42 curriculum by stehoffm*
# Libft
## Description:

This project is about building a custom C library from scratch.

The first part consists of reimplementing standard functions from existing C libraries by following the behavior described in the system manual pages.

The second part adds additional utility functions, mainly focused on string manipulation, while also serving as an introduction to concepts that are important for later work involving file descriptors. Each function is documented with a brief description of its prototype, return value, parameters, authorized external functions, and intended behavior.

The third part focuses on singly linked lists using a provided `struct` that must be included in the header file. As in the previous sections, each function is accompanied by a short description covering its prototype, return value, parameters, authorized external functions, and purpose.

All implemented functions are written in separate `.c` source files, compiled into `.o` object files, and archived into the required static library `libft.a`.

To build the library, the project also requires a `Makefile` that compiles the source files with the header and creates the final archive.

## Instructions:

To generate the static library `libft.a`, run `make` in the terminal.

This invokes the default target, `all`, which compiles each source file into an object file (`.o`) using the `-c` flag. The object files are then archived into the final static library, `libft.a`.

The Makefile also provides the following `.PHONY` targets:

### `make`
Builds the default target, `all`, and creates `libft.a`.

### `make clean`
Removes all generated object files (`.o`).

### `make fclean`
Executes `clean` and additionally removes the archive `libft.a`.

### `make re`
Executes `fclean` followed by `all`, fully rebuilding the project from scratch.

### How to include it in your files
Include any function from the library plus the `header` inside a folder called libft in the project, in that you want to use the library.
The whole libft files should be in that folder including the `Makefile`
```
#include "libft/libft.h"
```

## Resources:

Several resources were used throughout this project to support learning, testing, and verification.

For function testing, I first created small custom testers for individual functions. Later, I also used two different Libft testers from GitHub to compare behavior and identify edge cases. In addition, I built my own tester repository, with AI-assisted support, to organize tests more effectively and export output into `.txt` files for easier analysis.

For linked list concepts, I studied the corresponding section of the CS50 course.

For understanding `Makefile` syntax and structure, I used the tutorial from `makefiletutorial.com`.

For deeper conceptual understanding of the memory-related functions in Part 1, I used ChatGPT as a study tool to clarify mechanisms such as byte-wise memory operations, copying behavior, and overlapping memory regions.

These resources were used as support for learning and validation. The implementation, debugging, and final review of the submitted code were carried out by me.

## Library Contents

### Part 1 - Libc function reimplementations

This part contains reimplementations of standard libc-style functions.  
It includes character classification functions, string length and search functions,
memory manipulation functions, comparison functions, numeric conversion,
and allocation-based utilities.

*`ft_isalpha` / `ft_isdigit` / `ft_isalnum` / `ft_isascii` / `ft_isprint` / `ft_strlen` / `ft_memset` / `ft_bzero` / `ft_memcpy` / `ft_memmove` / `ft_strlcpy` / `ft_strlcat` / `ft_toupper` / `ft_tolower` / `ft_strchr` / `ft_strrchr` / `ft_strncmp` / `ft_memchr` / `ft_memcmp` / `ft_strnstr` / `ft_atoi` / `ft_calloc` / `ft_strdup`*

### Part 2 - Additional utility functions

This part contains additional utility functions that are not part of the standard libc
in the same form. These functions mainly focus on string creation and transformation,
as well as output to file descriptors.

*`ft_substr` / `ft_strjoin` / `ft_strtrim` / `ft_split` / `ft_itoa` / `ft_strmapi` / `ft_striteri` / `ft_putchar_fd` / `ft_putstr_fd` / `ft_putendl_fd` / `ft_putnbr_fd`*

### Part 3 - Linked list functions

This part contains functions for working with singly linked lists using the `t_list`
structure provided in the subject. These functions allow creation, traversal, insertion,
deletion, iteration, and mapping of list nodes.

*`ft_lstnew` / `ft_lstadd_front` / `ft_lstadd_back` / `ft_lstsize` / `ft_lstlast` / `ft_lstdelone` / `ft_lstclear` / `ft_lstiter` / `ft_lstmap`*