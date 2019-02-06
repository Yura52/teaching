#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>


template<typename T>
T Min(const T& first, const T& second) {
    return first < second ? first : second;
}


template<typename T>
T Read(std::istream& input = std::cin) {
    T value;
    input >> value;
    return value;
}


template<class F, class T>
bool ApplyPredicate(F predicate, T value) {
    return predicate(value);
}


int main() {
    // You have to put something in "<...>", in a different way the compiler doesn't know
    // what type to use as "T"
    const auto n = Read<int>();
    const auto s = Read<std::string>();
    // Now you can omit "<...>", because the compiler can infer "T" from the arguments
    std::cout << std::boolalpha << Min(n, n + 1) << " " << Min(s, s + "hello") << '\n';
    std::cout << ApplyPredicate(isdigit, 'a') << '\n';

    return 0;
}
