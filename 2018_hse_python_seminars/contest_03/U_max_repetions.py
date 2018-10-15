current_number = int(input())
max_repetitions_count = 0
while current_number != 0:
    repetition_count = 1
    new_current_number = int(input())
    while current_number == new_current_number:
        repetition_count += 1
        new_current_number = int(input())
    if repetition_count > max_repetitions_count:
        max_repetitions_count = repetition_count
    current_number = new_current_number
print(max_repetitions_count)
