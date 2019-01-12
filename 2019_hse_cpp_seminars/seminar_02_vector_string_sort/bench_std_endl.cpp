#include <chrono>
#include <iostream>
#include <fstream>


int main() {
    std::ofstream f1("tmp1.txt");
    auto t1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10000000; ++i) {
        f1 << 'a' << std::endl;
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    double d1 = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

    std::ofstream f2("tmp2.txt");
    auto t3 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10000000; ++i) {
        f2 << 'a' << '\n';
    }
    auto t4 = std::chrono::high_resolution_clock::now();
    double d2 = std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();

    std::cout << "std::endl "  << (d1 / 1000000) << '\n';
    std::cout << "\\n        " << (d2 / 1000000) << '\n';

    return 0;
}
