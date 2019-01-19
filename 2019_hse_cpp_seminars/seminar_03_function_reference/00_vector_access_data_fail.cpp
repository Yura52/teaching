#include <cstdint>
#include <iostream>
#include <vector>


using i32 = int32_t;


int main() {
    std::vector<i32> a;
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    std::cout << a[3] << '\n';
    std::cout << a.at(3) << '\n';

    return 0;
}
