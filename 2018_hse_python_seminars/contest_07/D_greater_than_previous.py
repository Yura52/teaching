import sys


numbers = map(int, sys.stdin.read().split())
previous = next(numbers)
for next_ in numbers:
    if previous < next_:
        print(next_)
    previous = next_
