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

max_length = max(map(len, files)) if files else 0
for line_index in range(max_length):
    lines = []
    for f in files:
        if line_index < len(f):
            lines.append(f[line_index])
        else:
            lines.append('')
    # six lines above can be replaced with one expression:
    # lines = [
    #     f[line_index] if line_index < len(f) else ''
    #     for f in files
    # ]
    print(*lines, sep='\t')
    # the same: print('\t'.join(lines))

for x in zip(*files):
    print(*x, sep='\t')
