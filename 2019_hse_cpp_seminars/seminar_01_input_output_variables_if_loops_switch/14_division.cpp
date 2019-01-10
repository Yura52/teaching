#include <cstdint>
#include <iostream>


using i32 = int32_t;


int main() {
    std::cout << "[int / int      ] " << 5   / 2   << '\n';
    std::cout << "[int / double   ] " << 5   / 2.0 << '\n';
    std::cout << "[double / int   ] " << 5.0 / 2   << '\n';
    std::cout << "[double / double] " << 5.0 / 2.0 << '\n';

    return 0;
}
