#include <iostream>

template<int n>
struct Factorial;

template<>
struct Factorial<0> {
    static const int value = 1;
};

template<int n>
struct Factorial {
    static const int value = n * Factorial<n - 1>::value;
};

template<int n>
const int FactorialValue = Factorial<n>::value;

template<typename U, typename V>
struct IsSame;

template<typename T>
struct IsSame<T, T> {
    static const bool value = true;
};

template<typename U, typename V>
struct IsSame {
    static const bool value = false;
};

template<typename U, typename V>
const bool IsSameValue = IsSame<U, V>::value;

int main() {
    std::cout << std::boolalpha;
    std::cout << FactorialValue<5> << '\n';
    std::cout << IsSameValue<int, int> << '\n';
    std::cout << IsSameValue<int, double> << '\n';

    return 0;
}
