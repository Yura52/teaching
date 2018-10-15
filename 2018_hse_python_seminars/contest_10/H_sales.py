import collections
import sys


name_to_item_counts = (
    collections.defaultdict(lambda: collections.defaultdict(int))
)
for line in sys.stdin:
    name, item, count = line.split()
    name_to_item_counts[name][item] += int(count)
for name in sorted(name_to_item_counts):
    print(f'{name}:')
    for item in sorted(name_to_item_counts[name]):
        print(f'{item} {name_to_item_counts[name][item]}')
