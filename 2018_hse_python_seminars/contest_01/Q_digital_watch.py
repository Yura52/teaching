second_count = int(input())
print('{}:{:02}:{:02}'.format(
    second_count // 3600 % 24,
    second_count // 60 % 60,
    second_count % 60
))
