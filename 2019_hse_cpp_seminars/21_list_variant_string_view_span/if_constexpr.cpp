#include <iostream>
#include <type_traits>


template<typename T>
void PrintType(const T& value) {
    if constexpr (std::is_same_v<T, int>) {
        std::cout << "int\n";
    } else {
        std::cout << "not int\n";
    }
}


int main() {
    PrintType(1);
    PrintType(2.0);

    return 0;
}
