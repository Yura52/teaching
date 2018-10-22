import itertools
import sys


def read_file():
    line_count = int(sys.stdin.readline())
    return [
        x.rstrip('\n')
        for x in itertools.islice(sys.stdin, line_count)
    ]


file_count = int(sys.stdin.readline())
files = [read_file() for _ in range(file_count)]
for x in itertools.zip_longest(*files, fillvalue=''):
    print(*x, sep='\t')

f1 = ['A', 'B']
f2 = ['C', 'D', 'E']
for x in itertools.zip_longest(f1, f2, fillvalue=''):
    # 0: ('A', 'C')
    # 1: ('B', 'D')
    # 2: ('', 'E')
