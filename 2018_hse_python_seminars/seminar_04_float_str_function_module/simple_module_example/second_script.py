def is_even(number: int) -> bool:
    return number % 2 == 0


def is_odd(number: int) -> bool:
    return number % 2 == 1


print(f'start {__name__}')
number = int(input())
print(f'even: {is_even(number)}')
print(f'odd: {is_odd(number)}')
print(f'end {__name__}')
