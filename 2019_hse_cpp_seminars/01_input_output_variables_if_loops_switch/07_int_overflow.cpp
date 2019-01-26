#include <cstdint>
#include <iostream>
#include <limits>


using i32 = int32_t;
using i64 = int64_t;


int MaxInt() {
    return std::numeric_limits<i32>::max();
}


/*
    Always think about types when doing arithmetics
*/
int main() {
    i32 a = MaxInt() + MaxInt();
    auto b = MaxInt() + MaxInt();
    i64 c = MaxInt() + MaxInt();
    auto d = static_cast<i64>(MaxInt()) + MaxInt();
    i64 e = static_cast<i64>(MaxInt()) + MaxInt();
    std::cout
        << "MaxInt(): " << MaxInt() << '\n'
        << "a: " << a << '\n'
        << "b: " << b << '\n'
        << "c: " << c << '\n'
        << "d: " << d << '\n'
        << "e: " << e << '\n';

    return 0;
}
