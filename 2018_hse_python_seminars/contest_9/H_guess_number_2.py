import sys


max_number = int(sys.stdin.readline())
candidates = set(range(1, max_number + 1))
for line in sys.stdin:
    line = line.strip()
    if line == 'HELP':
        break

    guess = set(map(int, line.split()))
    candidates_if_yes = candidates & guess
    if 2 * len(candidates_if_yes) > len(candidates):
        candidates = candidates_if_yes
        message = 'YES'
    else:
        candidates -= guess
        message = 'NO'
    print(message)

print(*sorted(candidates))
