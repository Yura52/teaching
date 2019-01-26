#include <cstdint>
#include <iostream>


using i32 = int32_t;


struct A {
    char b1;
    char b2;
    char b3;
    char b4;
    i32 a1;
    i32 a2;
    i32 a3;
    i32 a4;
};


struct B {
    char b1;
    i32 a1;
    char b2;
    i32 a2;
    char b3;
    i32 a3;
    char b4;
    i32 a4;
};


int main() {
    std::cout << sizeof(A) << ' ' << sizeof(B) << '\n';

    return 0;
}
