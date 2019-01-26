#include <algorithm>
#include <cstdint>
#include <functional>
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
    std::vector<i32> v = {5, 1, 3, 4, 2};
    std::cout << "Before sorting:\n";
    PrintVector(v);
    std::sort(v.begin(), v.end(), std::greater<i32>());
    std::cout << "After sorting:\n";
    PrintVector(v);

    return 0;
}
