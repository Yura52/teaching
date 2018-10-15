start_column = int(input())
start_row = int(input())
target_column = int(input())
target_row = int(input())

if target_row - start_row < 0:
    message = 'NO'
elif (start_column + start_row) % 2 != (target_column + target_row) % 2:
    message = 'NO'
elif target_row - start_row >= abs(target_column - start_column):
    message = 'YES'
else:
    message = 'NO'
print(message)
