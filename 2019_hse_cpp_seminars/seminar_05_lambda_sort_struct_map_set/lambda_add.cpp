#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>


using i32 = int32_t;


int main() {
    const auto add = [](auto a, auto b) {
        return a + b;
    };
    std::cout << add(2, 3) << '\n';

    std::vector<i32> a = {1, 2, 3};
    std::vector<i32> b;
    b.reserve(a.size());
    std::transform(a.begin(), a.end(), std::back_inserter(b), [](auto x) {
        return x * 2;
    });
    std::cout << b[0] << ' ' << b[1] << ' ' << b[2] << '\n';

    return 0;
}
