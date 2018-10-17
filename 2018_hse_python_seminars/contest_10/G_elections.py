import collections
import sys


vote_counts = collections.Counter(sys.stdin)
total_vote_count = sum(vote_counts.values())
top_two = vote_counts.most_common(2)
if top_two[0][1] * 2 > total_vote_count:
    print(top_two[0][0])
else:
    print(top_two[0][0], top_two[1][0])
