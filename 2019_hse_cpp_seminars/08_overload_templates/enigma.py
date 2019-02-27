#!/usr/bin/env python3
import random
import timeit

count = 1000000
false_then_true = [False] * (count // 2) + [True] * (count // 2)
mixed = false_then_true.copy()
random.shuffle(mixed)

code = """
for x in {array}:
    if x:
        pass
"""

print(
    'false_then_true: ',
    timeit.timeit(code.format(array='false_then_true'), number=10, globals=globals())
)
print(
    'mixed:           ',
    timeit.timeit(code.format(array='mixed'), number=10, globals=globals())
)
