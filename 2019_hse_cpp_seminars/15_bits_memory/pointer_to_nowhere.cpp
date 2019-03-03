#include <cstdint>
#include <iostream>

using i32 = int32_t;

int main() {
    i32 x = 0;
    i32* p = &x;
    *p = 123;
    std::cout << *p << '\n';

    i32* q = new i32{0};
    *q = 123;
    std::cout << *q << '\n';
    delete q;

    return 0;
}
