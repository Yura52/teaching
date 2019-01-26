#include <numeric>
#include <cstdint>
#include <iostream>
#include <vector>


using i32 = int32_t;


std::vector<i32>& BuildRange(const size_t size) {
    std::vector<i32> v(size);
    std::iota(v.begin(), v.end(), 0);
    std::cout
        << "v[9]:     " << v[9] << '\n'
        << "v.back(): " << v.back() << '\n';
    return v;
}

int main() {
    auto& new_v = BuildRange(10);
    std::cout
        << "new_v[9]:     " << new_v[9] << '\n'
        << "new_v.back(): " << new_v.back() << '\n';
    std::cout << "what??\n";

    std::cout << "Ok, totally new vector:\n";
    auto super_new_v = BuildRange(10);

    return 0;
}
