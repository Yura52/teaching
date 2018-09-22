coefficient_count = int(input()) + 1
x = float(input())
value = 0

while coefficient_count:
    value = value * x + float(input())
    coefficient_count -= 1
print(value)
