#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>


using i32 = int32_t;


template<typename T>
T Min(const T& first, const T& second) {
    return first < second ? first : second;
}


template<typename T>
T Read(std::istream& input = std::cin) {
    T value;
    input >> value;
    return value;
}


int main() {
    const auto n = Read<i32>();
    const auto s = Read<std::string>();
    std::cout << std::boolalpha << (n, n) << " " << Min(s, s) << '\n';

    return 0;
}
