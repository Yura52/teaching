// POD means "plain old data"
#include <cstdint>
#include <iostream>


using i32 = int32_t;


int main() {
    int a = 123;
    char b = 'A';
    bool c = true;
    double d = 1.23;
    std::cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';

    return 0;
}
