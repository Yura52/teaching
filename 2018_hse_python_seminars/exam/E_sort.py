import math
import sys


flags = sys.stdin.readline().split()
# keys_and_lines is a list of tuples: (key_for_sorting, original_line)
keys_and_lines = []
for line in map(lambda x: x.rstrip('\n'), sys.stdin):
    key = line
    if '-b' in flags:
        key = key.lstrip()
    if '-f' in flags:
        key = key.lower()
    if '-g' in flags:
        lstripped_line = line.lstrip()
        starts_with_minus = lstripped_line.startswith('-')
        digit_end_index = 1 if starts_with_minus else 0
        while (
            digit_end_index < len(lstripped_line) and
            lstripped_line[digit_end_index].isdigit()
        ):
            digit_end_index += 1
        # line = '   -123abc'
        # lstripped_line = '-123abc'
        # starts_with_minus = True
        # digit_end_index = 1
        # ...
        # digit_end_index = 4
        starts_with_number = (
            not starts_with_minus and digit_end_index > 0 or
            starts_with_minus and digit_end_index > 1
        )
        number = (
            int(lstripped_line[:digit_end_index])
            if starts_with_number
            else -math.inf
        )
        key = (number, key)
    keys_and_lines.append((key, line))

for key, line in sorted(keys_and_lines, reverse='-r' in flags):
    print(line)
