import itertools
import operator
import sys

number = int(sys.stdin.readline())
print(
    1,
    *itertools.accumulate(range(1, number + 1), operator.mul),
    sep='\n',
    end=''
)
