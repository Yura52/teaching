first_number = int(input())
second_number = int(input())
first_quotient = first_number // second_number
second_quotient = second_number // first_number
print(
    (first_quotient * first_number + second_quotient * second_number) //
    (first_quotient + second_quotient)
)
