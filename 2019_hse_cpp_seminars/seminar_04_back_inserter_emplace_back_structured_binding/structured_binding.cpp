#include <cstdint>
#include <iostream>
#include <utility>


using i32 = int32_t;


std::pair<i32, i32> MakePair() {
    return std::make_pair(0, 0);
}


std::tuple<i32, i32, i32> MakeTuple() {
    return std::make_tuple(0, 0, 0);
}


struct MyPair {
    i32 left{0};
    i32 right{0};
};


int main() {
    std::pair<i32, i32> p = {1, 2};
    const auto [a, b] = p;

    std::tuple<i32, i32, i32> t{1, 2, 3};
    const auto [c, d, e] = t;

    const auto [f, g] = MakePair();
    const auto [h, i, j] = MakeTuple();

    const auto [k, l] = MyPair{10, 20};

    return 0;
}
