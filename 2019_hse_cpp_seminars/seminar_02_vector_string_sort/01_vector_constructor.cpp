#include <cstdint>
#include <iostream>
#include <vector>


using i32 = int32_t;


void PrintVector(const std::vector<i32>& v) {
    std::cout
        << "empty: " << std::boolalpha << v.empty() << '\n'
        << "size: " << v.size() << '\n'
        << "capacity: " << v.capacity() << '\n'
        << "data: ";
    for (const auto x: v) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
    std::cout << '\n';
}


/*
    Remember about the difference between "()" and "{}"
*/
int main() {
    std::cout << "=== a ===\n";
    std::vector<i32> a;
    PrintVector(a);

    std::cout << "=== b ===\n";
    std::vector<i32> b = {0, 1, 2};
    PrintVector(b);

    std::cout << "=== c ===\n";
    std::vector<i32> c(5);
    PrintVector(c);

    std::cout << "=== d ===\n";
    std::vector<i32> d(5, 3);
    PrintVector(d);

    std::cout << "=== e ===\n";
    std::vector<i32> e{5, 3};
    PrintVector(e);

    return 0;
}
