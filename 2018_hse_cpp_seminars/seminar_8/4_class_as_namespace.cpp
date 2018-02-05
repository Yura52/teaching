#include <iostream>

class A {
public:
    using type = int;
    static const int value{0};
};

template<typename T>
class Vector {
public:
    using value_type = T;
    using reference = T&;
    using pointer = T*;
};

template<int A, int B>
struct Sum {
    static const int value = A + B;
};

template<int N>
struct Fib;

template<>
struct Fib<0> {
    static const int value = 0;
};

template<>
struct Fib<1> {
    static const int value = 1;
};

// 
template<int N>
struct Fib {
    static const int value = Fib<N - 1>::value + Fib<N - 2>::value;
};

template<typename U, typename V>
struct IsSame {
    static const bool value = false;
};

template<typename T>
struct IsSame<T, T> {
    static const bool value = true;
};


int main() {
    Vector<int>::value_type a = A::value;
    Vector<int>::value_type b = Sum<1, 1>::value;

    std::cout << a << '\n';
    std::cout << b << '\n';
    std::cout << Fib<5>::value << '\n';

    std::cout << std::boolalpha << IsSame<int, double>::value << '\n';
    std::cout << std::boolalpha << IsSame<int, int>::value << '\n';

    return 0;
}
