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
    item_counts = name_to_item_counts[name]
    for item in sorted(item_counts):
        print(f'{item} {item_counts[item]}')
