#include <cstdint>
#include <iostream>


using i32 = int32_t;


int main() {
    i32 a = 0;
    std::cout << "enter a:\n";
    std::cin >> a;
    if (a > 1) {
        std::cout << "a is greater than 1\n";
    } else {
        std::cout << "a is less or equal than 1\n";
    }

    switch (a) {
        case 0: {
            std::cout << "a equals 0\n";
            break;
        }

        case 1: {
            std::cout << "a equals 1\n";
            break;
        }

        default: {
            std::cout << "a is not equal to 0 nor 1\n";
            break;
        }
    }

    return 0;
}
