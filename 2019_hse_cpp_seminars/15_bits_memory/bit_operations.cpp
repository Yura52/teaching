#include <iostream>
#include <cstdint>

using i32 = int32_t;

i32 LeftShift(i32 value, i32 shift) {
    return value << shift;
}

i32 RightShift(i32 value, i32 shift) {
    return value >> shift;
}

bool TestBit(i32 value, i32 bit_index) {
    return value & LeftShift(1, bit_index);
}

i32 GetBit(i32 value, i32 bit_index) {
    return TestBit(value, bit_index) ? 1 : 0;
}

i32 FlipBit(i32 value, i32 bit_index) {
    return value ^ LeftShift(1, bit_index);
}

i32 SetBit(i32 value, i32 bit_index) {
    return value | LeftShift(1, bit_index);
}

i32 ResetBit(i32 value, i32 bit_index) {
    return value & ~LeftShift(1, bit_index);
}

int main() {
    i32 a = 2;
    std::cout << LeftShift(a, 1) << '\n';
    std::cout << RightShift(a, 1) << '\n';

    i32 b = 1;
    for (i32 i = 31; i >= 0; --i) {
        std::cout << TestBit(b, i);
    }
    std::cout << '\n';

    i32 c = -1;
    for (i32 i = 31; i >= 0; --i) {
        std::cout << TestBit(c, i);
    }
    std::cout << '\n';

    return 0;
}
