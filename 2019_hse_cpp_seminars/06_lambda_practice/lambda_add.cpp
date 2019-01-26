#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>


using i32 = int32_t;


int main() {
    const auto add = [](auto a, auto b) {
        return a + b;
    };
    std::cout << add(2, 3) << '\n';

    return 0;
}
