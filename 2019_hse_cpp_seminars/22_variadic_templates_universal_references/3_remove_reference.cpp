#include <iostream>
#include <type_traits>

template<class T>
struct RemoveReference {
    using type = T;
};

template<class T>
struct RemoveReference<T&> {
    using type = T;
};

template<class T>
struct RemoveReference<T&&> {
    using type = T;
};

int main() {
    RemoveReference<int&>::type x = 5;
    std::cout << std::is_same_v<decltype(x), int> << '\n';

    return 0;
}
