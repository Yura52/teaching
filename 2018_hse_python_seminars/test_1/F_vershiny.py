import sys


heights = map(int, sys.stdin)
left_height = next(heights)
middle_height = left_height
left_is_less = False
count = 0
for right_height in heights:
    left_is_less = left_height < middle_height
    if left_is_less and middle_height > right_height:
        count += 1
    left_height, middle_height = middle_height, right_height
if left_is_less:
    count -= 1
print(count)
