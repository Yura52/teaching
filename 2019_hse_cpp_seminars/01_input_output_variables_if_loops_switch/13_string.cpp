#include <cstdint>
#include <iostream>
#include <string>


using i32 = int32_t;


int main() {
    const std::string s = "hello";
    for (i32 i = 0; i < s.size(); ++i) {
        std::cout << s[i];
    }
    std::cout << '\n';
    for (const auto x: s) {
        std::cout << x;
    }
    std::cout << '\n';

    return 0;
}
