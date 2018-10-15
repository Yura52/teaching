import itertools
import sys


day_count_per_year, party_count = map(int, sys.stdin.readline().split())
strike_days = set()
for line in sys.stdin:
    first_day, period = map(int, line.strip().split())
    strike_days.update(range(first_day, day_count_per_year + 1, period))
for first_weekend in (6, 7):
    strike_days.difference_update(
        range(first_weekend, day_count_per_year + 1, 7)
    )
print(len(strike_days))
