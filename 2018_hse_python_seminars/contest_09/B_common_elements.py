import sys


first_set = set(sys.stdin.readline().split())
first_set.intersection_update(sys.stdin.readline().split())
for x in sys.stdin.readline().split():
    first_set.discard(x)
print(len(first_set))
