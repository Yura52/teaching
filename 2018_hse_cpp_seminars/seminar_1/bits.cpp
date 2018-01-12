#include <bitset>
#include <iostream>
#include <string>

int main(const int argc, const char* argv[]) {
    const auto number = std::stoul(argv[1]);
    const auto ptr = reinterpret_cast<const uint8_t*>(&number);
    for (size_t i = 0; i < sizeof(number); ++i) {
        std::cout << std::bitset<8>(*(ptr + i)) << ' ';
    }
    std::cout << '\n';
}
