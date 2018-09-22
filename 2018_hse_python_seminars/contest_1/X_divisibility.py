a = int(input())
b = int(input())
r = a % b
c = (a - r) // a  # 0 or 1
print('YES' * c + 'NO' * (1 - c))
