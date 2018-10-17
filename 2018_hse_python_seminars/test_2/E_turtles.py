import itertools
import sys


turtle_count = int(sys.stdin.readline())
flags = [False for _ in range(turtle_count)]
for line in itertools.islice(sys.stdin, turtle_count):
    a, b = map(int, line.split())
    if a >= 0 and b >= 0 and a + b + 1 == turtle_count:
        flags[a] = True
print(flags.count(True))
