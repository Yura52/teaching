first_number = int(input())
second_number = int(input())
third_number = int(input())

if first_number < second_number:
    first_number, second_number = second_number, first_number
if second_number < third_number:
    second_number, third_number = third_number, second_number
if first_number < second_number:
    first_number, second_number = second_number, first_number
print(third_number, second_number, first_number)
