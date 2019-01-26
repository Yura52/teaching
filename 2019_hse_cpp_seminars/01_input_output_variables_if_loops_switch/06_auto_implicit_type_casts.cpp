#include <cstdint>
#include <iostream>


using i32 = int32_t;


/*
    use `auto` to avoid mistakes caused by implicit type casts
*/
int main() {
    i32 a = 1 + 0.1;
    auto b = 1 + 0.1;
    std::cout
        << "a: " << a << '\n'
        << "b: " << b << '\n';

    return 0;
}
