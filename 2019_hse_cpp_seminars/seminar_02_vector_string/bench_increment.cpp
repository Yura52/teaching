#include <chrono>
#include <iostream>
#include <vector>


int main() {
    std::vector<int> v1(1000000, 0);
    auto t1 = std::chrono::high_resolution_clock::now();
    for (auto it = v1.begin(); it != v1.end(); it++) {}
    auto t2 = std::chrono::high_resolution_clock::now();
    double d1 = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

    std::vector<int> v2(1000000, 0);
    auto t3 = std::chrono::high_resolution_clock::now();
    for (auto it = v2.begin(); it != v2.end(); ++it) {}
    auto t4 = std::chrono::high_resolution_clock::now();
    double d2 = std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();

    std::cout << "it++ " << (d1 / 1000000) << '\n';
    std::cout << "++it " << (d2 / 1000000) << '\n';

    return 0;
}
