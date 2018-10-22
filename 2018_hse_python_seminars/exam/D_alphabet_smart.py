import collections
import itertools
import sys


lines = map(lambda x: x.rstrip('\n'), sys.stdin)
alphabet_count = int(next(lines))
letter_to_alphabets = collections.defaultdict(set)
while alphabet_count:
    alphabet_count -= 1
    name = next(lines)
    for letter in next(lines):
        letter_to_alphabets[letter].add(name)

query_count = int(sys.stdin.readline())
for query in itertools.islice(sys.stdin, query_count):
    possible_alphabets = itertools.chain.from_iterable(
        letter_to_alphabets.get(letter, set())
        for letter in query
    )
    print(*sorted(set(possible_alphabets)))
