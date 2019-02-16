#include <iostream>

// C++17
class A {
public:
    inline static int a = 0;
};

// Before C++17
// class A {
// public:
//     static int a;
// };
// int A::a = 0;

int main() {
    A x;
    A y;
    ++x.a;
    std::cout << &x.a  << ' ' << x.a  << '\n';
    std::cout << &y.a  << ' ' << y.a  << '\n';
    std::cout << &A::a << ' ' << A::a << '\n';
    std::cout << sizeof(x) << '\n';
    return 0;
}
