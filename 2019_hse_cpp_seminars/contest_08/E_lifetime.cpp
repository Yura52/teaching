#include "c.h"
#include <iostream>
#include <vector>

int main() {
    size_t count = 0;
    std::cin >> count;
    if (!count) {
        return 0;
    }

    std::vector<C> v;
    v.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        v.emplace_back();
    }
    while (!v.empty()) {
        v.pop_back();
    }
    return 0;
}
