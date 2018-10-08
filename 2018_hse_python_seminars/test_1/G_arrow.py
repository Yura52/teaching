import sys


DEGREE_COUNT_PER_HOUR = 360 / 12
DEGREE_COUNT_PER_MINUTE = DEGREES_PER_HOUR / 60
DEGREE_COUNT_PER_SECOND = DEGREE_COUNT_PER_MINUTE / 60
hour_count, minute_count, second_count = map(int, sys.stdin)
print(
    hour_count * DEGREE_COUNT_PER_HOUR +
    minute_count * DEGREE_COUNT_PER_MINUTE +
    second_count * DEGREE_COUNT_PER_SECOND
)
