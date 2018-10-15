import my_module.my_functions as my_functions


def main():
    number = int(input())
    print(f'even: {my_functions.is_even(number)}')


if __name__ == '__main__':
    main()
