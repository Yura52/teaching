import copy
import sys


def is_polyndrom(sequence):
    return sequence == sequence[::-1]


number_count = int(sys.stdin.readline())
numbers = list(map(int, sys.stdin.readline().split()))
if is_polyndrom(numbers):
    print(0)
else:
    sequence = numbers
    for count in range(1, number_count):
        sequence = numbers + numbers[:count][::-1]
        if is_polyndrom(sequence):
            break
    print(count)
    print(*sequence[-count:])
