import sys

print(*map(
    lambda x: x[0] ^ x[1],
    zip(
        map(int, sys.stdin.readline().split()),
        map(int, sys.stdin.readline().split())
    )
))
