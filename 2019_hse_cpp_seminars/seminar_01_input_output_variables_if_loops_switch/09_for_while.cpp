#include <cstdint>
#include <iostream>


using i32 = int32_t;


int main() {
    i32 a = -1;
    while (a <= 0) {
        std::cout << "enter a POSITIVE integer: ";
        std::cin >> a;
    }

    for (i32 i = 0; i < a; ++i) {
        std::cout << i << " ";
    }
    std::cout << '\n';

    return 0;
}
