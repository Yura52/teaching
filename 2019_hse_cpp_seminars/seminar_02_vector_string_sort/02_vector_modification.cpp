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
    Never use `push_front` and `insert`: they are extremely performance-unfriendly
*/
int main() {
    std::cout << "=== a ===\n";
    std::vector<i32> a;
    PrintVector(a);

    std::cout << "=== push_back ===\n";
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    PrintVector(a);

    std::cout << "=== pop_back ===\n";
    a.pop_back();
    PrintVector(a);

    std::cout << "=== clear ===\n";
    a.clear();
    PrintVector(a);

    return 0;
}
