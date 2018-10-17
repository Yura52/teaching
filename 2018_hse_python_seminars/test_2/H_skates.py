import sys


skates = sorted(map(int, sys.stdin.readline().split()))
legs = sorted(map(int, sys.stdin.readline().split()))
skate_index = 0
leg_index = 0
while skate_index < len(skates) and leg_index < len(legs):
    if skates[skate_index] >= legs[leg_index]:
        leg_index += 1
    skate_index += 1
print(leg_index)
