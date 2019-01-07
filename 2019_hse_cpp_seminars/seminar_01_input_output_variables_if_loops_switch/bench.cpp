#include <algorithm>
#include <cstdint>
#include <chrono>
#include <iostream>
#include <vector>


using i64 = int64_t;


i64 job(i64 size) {
    std::vector<i64> v;
    for (i64 i = 0; i < size; ++i) {
        v.push_back(i);
    }
    return *std::max_element(std::begin(v), std::end(v));
}


int main() {
    const auto t1 = std::chrono::high_resolution_clock::now();
    const auto result = job(10000000);
    const auto t2 = std::chrono::high_resolution_clock::now();
    double duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout << "result: " << result << '\n' << "duration: " << (duration / 1000000) << '\n';

    return 0;
}
