#include "c.h"
#include <deque>
#include <iostream>

int main() {
    size_t count = 0;
    std::cin >> count;
    if (!count) {
        return 0;
    }

    std::deque<C> d;
    for (size_t i = 0; i < count; ++i) {
        d.emplace_back();
    }
    while (!d.empty()) {
        d.pop_front();
    }
    return 0;
}
