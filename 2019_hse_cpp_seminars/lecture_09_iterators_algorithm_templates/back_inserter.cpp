#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>


void PrintVector(const std::vector<int>& v) {
    std::cout << "data: ";
    for (const auto x: v) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}


int main() {
    std::vector<int> a = {1, 2, 3};
    PrintVector(a);

    auto it = std::back_inserter(a);
    *it = 4;
    PrintVector(a);

    std::vector<int> b(a.size());
    std::copy(a.begin(), a.end(), b.begin());
    PrintVector(b);

    std::vector<int> c;
    std::copy(a.begin(), a.end(), std::back_inserter(c));
    PrintVector(c);

    return 0;
}
