#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>


using i32 = int32_t;


void PrintVector(const std::vector<i32>& v) {
    std::cout << "data: ";
    for (const auto x: v) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}


int main() {
    std::vector<i32> a = {1, 2, 3};
    PrintVector(a);

    auto it = std::back_inserter(a);
    *it = 4;
    PrintVector(a);

    std::vector<i32> b(a.size());
    std::copy(a.cbegin(), a.cend(), b.begin());
    PrintVector(b);

    std::vector<i32> c;
    c.reserve(a.size());
    std::copy(a.cbegin(), a.cend(), std::back_inserter(c));
    PrintVector(c);

    return 0;
}
