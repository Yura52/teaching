import itertools
import operator
import sys


n = int(sys.stdin.readline())
# n = 3
factorials = itertools.accumulate(range(1, n + 1), operator.mul)
# list(factorials) == [1, operator.mul(1, 2) == 2, operator.mul(2, 3) == 6]
print(sum(factorials))
