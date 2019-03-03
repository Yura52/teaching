#include <cstdint>
#include <iostream>
#include <string>

using u64 = uint64_t;

u64 LoadVarint(const std::string& s) {
    u64 number = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        u64 x = s[i];
        // оставить в x только младшие 7 бит
        // оставить в number младшие 7 * i бит и заполнить следующие после них 7 бит младшими битами x
    }
    return number;
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::cout << LoadVarint(s) << '\n';

    return 0;
}
