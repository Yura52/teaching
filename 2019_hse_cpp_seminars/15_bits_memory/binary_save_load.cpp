#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>
#include <ios>

using i32 = int32_t;

int main() {
    std::vector<i32> v = {1, 2, 3, 4};
    std::ofstream f("v.bin", std::ios::binary);
    const auto v_size = v.size();
    f.write(
        reinterpret_cast<const char*>(&v_size),
        sizeof(v_size)
    );
    f.write(
        reinterpret_cast<const char*>(v.data()),
        v_size * sizeof(i32)
    );
    f.close();

    std::vector<i32> w;
    std::ifstream g("v.bin", std::ios::binary);
    size_t w_size = 0;
    g.read(
        reinterpret_cast<char*>(&w_size),
        sizeof(w_size)
    );
    w.resize(w_size, 0);
    g.read(
        reinterpret_cast<char*>(w.data()),
        w_size * sizeof(i32)
    );
    for (auto x: w) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    // i32 x = 12345678;
    // std::ofstream f("x.bin", std::ios::binary);
    // f.write(
    //     reinterpret_cast<char*>(&x),
    //     sizeof(x)
    // );
    // f.close();

    // std::ifstream g("x.bin", std::ios::binary);
    // i32 y = 0;
    // g.read(
    //     reinterpret_cast<char*>(&y),
    //     sizeof(y)
    // );
    // std::cout << y << '\n';

    return 0;
}
