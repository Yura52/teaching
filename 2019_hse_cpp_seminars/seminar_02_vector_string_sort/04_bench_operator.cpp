#include <algorithm>
#include <cstdint>
#include <chrono>
#include <iostream>
#include <vector>


using i64 = int64_t;


const i64 kSize = 10000000;


int main() {
    std::vector<i64> a(kSize);
    const auto t1 = std::chrono::high_resolution_clock::now();
    for (i64 i = 0; i < kSize; ++i) {
        a[i] = i;
    }
    const auto t2 = std::chrono::high_resolution_clock::now();
    double duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout << "duration: " << (duration / 1000000) << '\n';

    return 0;
}
