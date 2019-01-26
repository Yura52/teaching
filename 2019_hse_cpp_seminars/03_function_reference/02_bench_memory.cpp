#include <chrono>
#include <iostream>
#include <vector>


int main() {
    int s = 0;
    auto t1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; ++i) {
        s += 1;
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    double d1 = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

    auto t3 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; ++i) {
        std::vector<int> v{0};
    }
    auto t4 = std::chrono::high_resolution_clock::now();
    double d2 = std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();

    std::cout << "add    " << (d1 / 1000000) << '\n';
    std::cout << "memory " << (d2 / 1000000) << '\n';

    return 0;
}
