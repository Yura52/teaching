def is_even(number: int) -> bool:
    return number % 2 == 0


print(f'start {__name__}')
number = int(input())
print(f'even: {is_even(number)}')
print(f'end {__name__}')
