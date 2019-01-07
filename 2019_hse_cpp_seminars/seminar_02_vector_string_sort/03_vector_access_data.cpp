#include <cstdint>
#include <iostream>
#include <vector>


using i32 = int32_t;


void PrintVector(const std::vector<int>& v) {
    std::cout
        << "empty: " << std::boolalpha << v.empty() << '\n'
        << "size: " << v.size() << '\n'
        << "capacity: " << v.capacity() << '\n'
        << "data: ";
    for (auto x: v) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
    std::cout << '\n';
}


/*
    Consider using `at` if performance is not extremely important
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

    std::cout << "=== print front & back ===";
    std::cout << "front: " << a.front() << '\n';
    std::cout << "back: " << a.back() << '\n';
    std::cout << '\n';

    std::cout << "=== operator[] ===\n";
    std::cout << "a[0]: " << a[0] << '\n';
    std::cout << "a[1]: " << a[1] << '\n';
    std::cout << "a[2]: " << a[2] << '\n';
    std::cout << "a[3]: " << a[3] << '\n';
    std::cout << '\n';

    std::cout << "=== at ===\n";
    std::cout << "a.at(0): " << a.at(0) << '\n';
    std::cout << "a.at(1): " << a.at(1) << '\n';
    std::cout << "a.at(2): " << a.at(2) << '\n';
    std::cout << "a.at(3): " << a.at(3) << '\n';
    std::cout << '\n';

    return 0;
}
