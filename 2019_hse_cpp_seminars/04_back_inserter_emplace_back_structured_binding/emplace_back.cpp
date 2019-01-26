#include <cstdint>
#include <iostream>
#include <string>
#include <vector>


using i32 = int32_t;


int main() {
    std::vector<std::string> v;
    v.emplace_back(5, 'a');
    std::cout << v.back() << '\n';

    std::string s = "hello";
    v.emplace_back(s.begin(), std::next(s.begin(), 3));
    std::cout << v.back() << '\n';

    return 0;
}
