#include <algorithm>
#include <cmath>
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


bool CompareByAbsoluteValue(const i32 first, const i32 second) {
    return std::abs(first) < std::abs(second);
}


int main() {
    std::vector<i32> v = {-5, -1, -3, 4, 2};
    std::cout << "Before sorting:\n";
    PrintVector(v);
    std::sort(v.begin(), v.end(), CompareByAbsoluteValue);
    std::cout << "After sorting:\n";
    PrintVector(v);

    return 0;
}
