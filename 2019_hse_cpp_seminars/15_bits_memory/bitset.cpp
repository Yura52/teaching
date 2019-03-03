#include <cstdint>
#include <iostream>
#include <utility>

using i32 = int32_t;

int main() {
    std::bitset<8> bs(6);
    std::cout << "[6    ] " << bs.to_string() << '\n';
    std::cout << "[flip ] " << bs.flip().to_string() << '\n';
    std::cout << "[set  ] " << bs.set(1).to_string() << '\n';
    std::cout << "[reset] " << bs.reset(1).to_string() << '\n';
    std::cout << "[count] " << bs.count() << '\n';
    std::cout << "[all  ] " << bs.all() << '\n';
    std::cout << "[any  ] " << bs.any() << '\n';
    std::cout << "[[1]  ] " << bs[1] << '\n';
    std::cout << "[[5]  ] " << bs[5] << '\n';

    return 0;
}
