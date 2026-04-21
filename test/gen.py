import sys
import random

size = int(sys.argv[1])
percent = int(sys.argv[2])

sorted_arr = list(range(1, size + 1))
reversed_arr = list(range(size, 0, -1))

# interpolate between sorted and reversed
# at 50% we do a full random shuffle
if percent <= 50:
    arr = sorted_arr[:]
    n = size * percent * 2 // 100  # how many elements to disorder
    indices = random.sample(range(size), n)
    values = [arr[i] for i in indices]
    random.shuffle(values)
    for i, idx in enumerate(indices):
        arr[idx] = values[i]
else:
    # start from reversed, gradually fix it toward sorted
    arr = reversed_arr[:]
    n = size * (100 - percent) * 2 // 100
    indices = random.sample(range(size), n)
    values = [arr[i] for i in indices]
    random.shuffle(values)
    for i, idx in enumerate(indices):
        arr[idx] = values[i]

print(*arr)