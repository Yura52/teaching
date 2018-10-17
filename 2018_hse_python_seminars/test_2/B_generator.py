import sys


def generate(max_number, count):
    candidates = range(1, max_number + 1)
    if count == 1:
        return [[x] for x in candidates]
    result = []
    for c in candidates:
        c_tails = generate(max_number, count - 1)
        for tail in c_tails:
            result.append([c] + tail)
    return result

count, max_number = map(int, sys.stdin.readline().split())
for x in generate(max_number, count):
    print(*x)
