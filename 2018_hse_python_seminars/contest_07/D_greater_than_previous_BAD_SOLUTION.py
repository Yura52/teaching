# Drawbacks of this solution:
# 1. Useless conversion from `map` to `list`.
# 2. Usage of indexing. It should be avoided and replaced with a loop over elements.
# 3. Worse readability.
# 4. Many implicit calls of `__getitem__` in the loop ==> the program is slower.
import sys


numbers = list(map(int, sys.stdin.read().split()))
for i in range(len(numbers) - 1):
    if numbers[i] < numbers[i + 1]:
        print(numbers[i + 1])
