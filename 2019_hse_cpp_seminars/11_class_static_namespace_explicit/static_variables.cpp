#include <cstdint>
#include <iostream>

using i64 = int64_t;

i64 GenerateId() {
    static i64 x = -1;
    ++x;
    return x;
}

int main() {
    std::cout << GenerateId() << '\n';
    std::cout << GenerateId() << '\n';
    std::cout << GenerateId() << '\n';

    return 0;
}
