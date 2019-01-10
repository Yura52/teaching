#include <cstdint>
#include <iostream>
#include <string>


using i32 = int32_t;


int main() {
    std::string s = "hello";

    // The best way to loop over a collection is "range-based for loop".
    // (a) If you don't need to modify the objects:
    for (const auto x: s) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    // (b) If you need to modify the objects:
    for (auto& x: s) {
        x *= 2;
    }

    // If "range-based for loop" doesn't solve your problem, use iterators
    // (a)
    for (auto it = s.cbegin(); it != s.cend(); ++it) {
        std::cout << *it << '\n';
    }

    // (b)
    for (auto it = s.begin(); it != s.end(); ++it) {
        *it *= 2;
    }

    // (c) Iterate in a reversed order (cannot be done via "range-based for loop")
    for (auto it = s.crbegin(); it != s.crend(); ++it) {
        std::cout << *it << '\n';
    }

    // Only if nothing above works for you, use indexing
    // (a)
    for (i32 i = 0; i < s.size(); ++i) {
        std::cout << s[i] << '\n';
    }

    // (d) Iterate over every second element
    // (cannot be solved via "range-based for loop" nor via iterators)
    for (i32 i = 0; i < s.size(); i += 2) {
        std::cout << s[i] << '\n';
    }

    return 0;
}
