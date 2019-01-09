#include <cstdint>
#include <iostream>


using i32 = int32_t;


// `char` is just a 8-bit integer
int main() {
    i32 a1 = 'a';
    char a2 = 'a';
    char digit = '6';
    std::cout << std::boolalpha << (a1 == a2) << ' ' << a1 << ' ' << a2 << '\n';
    // the result of `digit - '0'` is int
    std::cout << digit << ' ' << (digit - '0') << '\n';

    return 0;
}
