# Avoid code duplication! See the "code_duplication_fixed.py" to see the
# better version of this script


start_column = int(input())
start_row = int(input())
target_column = int(input())
target_row = int(input())

if target_row - start_row < 0:
    print('NO')
elif (start_column + start_row) % 2 != (target_column + target_row) % 2:
    print('NO')
elif target_row - start_row >= abs(target_column - start_column):
    print('YES')
else:
    print('NO')
