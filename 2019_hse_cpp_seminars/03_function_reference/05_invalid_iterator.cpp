#include <cstdint>
#include <iostream>
#include <vector>


using i32 = int32_t;


int main() {
    std::vector<i32> v = {10};
    auto it = v.begin();
    std::cout << "*it " << *it << '\n';
    v.push_back(20);
    std::cout << "*it " << *it << '\n';
    // try two duplicate two previous lines ~10 times

    return 0;
}
