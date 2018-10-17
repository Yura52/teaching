import itertools
import sys


print(len(set(itertools.chain.from_iterable(
    map(str.split, sys.stdin)
))))
