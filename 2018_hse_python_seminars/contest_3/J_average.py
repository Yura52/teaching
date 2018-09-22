sum_ = 0.0
current_number = int(input())
number_count = 0
while current_number != 0:
    sum_ += current_number
    number_count += 1
    current_number = int(input())
print(sum_ / number_count)
