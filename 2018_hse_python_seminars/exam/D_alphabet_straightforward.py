import itertools
import sys


alphabet_count = int(sys.stdin.readline())
alphabets = {}
while alphabet_count:
    alphabet_count -= 1
    name = sys.stdin.readline().rstrip('\n')
    letters = set(sys.stdin.readline().rstrip('\n'))
    alphabets[name] = letters

# alphabets = {'English': {'a', 'b', ...}, 'PC': {'0, '1'}}
query_count = int(sys.stdin.readline())
for query in itertools.islice(sys.stdin, query_count):
    query = set(query.rstrip('\n'))
    possible_alphabets = []
    for name, letters in alphabets.items():
        if query & letters:
            possible_alphabets.append(name)
    print(*sorted(possible_alphabets))
