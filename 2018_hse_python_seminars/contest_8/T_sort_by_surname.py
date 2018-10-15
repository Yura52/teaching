import sys


for x in sorted(sys.stdin):
    x = x.split()
    print(x[0], x[1], x[3])
