#include <chrono>
#include <iostream>
#include <vector>


int main() {
    std::vector<int> v1;
    v1.reserve(10000000);
    auto t1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10000000; ++i) {
        v1.push_back(i);
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    double d1 = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

    std::vector<int> v2;
    auto t3 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10000000; ++i) {
        v2.push_back(i);
    }
    auto t4 = std::chrono::high_resolution_clock::now();
    double d2 = std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();

    std::cout << "reserve    " << (d1 / 1000000) << '\n';
    std::cout << "no reserve " << (d2 / 1000000) << '\n';

    return 0;
}
