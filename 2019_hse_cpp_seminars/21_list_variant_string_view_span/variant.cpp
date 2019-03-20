#include <iomanip>
#include <iostream>
#include <string>
#include <variant>
#include <vector>

using Variant = std::variant<int, long, double, std::string>;

int main()
{
    std::variant<int, float> v{12};
    int x = std::get<int>(v);
    int y = std::get<0>(v); // same effect as the previous line
 
    // std::get<double>(v); // error: no double in [int, float]
    // std::get<3>(v);      // error: valid index values are 0 and 1
 
    try {
        std::get<float>(v); // w contains int, not float: will throw
    }
    catch (std::bad_variant_access&) {
        std::cout << "The object contains int, not float!\n";
    }

    std::vector<Variant> vec = {10, 15l, 1.5, "hello"};
    for(auto& v: vec) {
 
        // 1. void visitor, only called for side-effects (here, for I/O)
        std::visit([](auto&& arg){std::cout << arg;}, v);
 
        // 2. value-returning visitor, demonstrates the idiom of returning another variant
        Variant w = std::visit([](auto&& arg) -> Variant {return arg + arg;}, v);
 
        // 3. type-matching visitor: a lambda that handles each type differently
        std::cout << ". After doubling, variant holds ";
        std::visit([](auto&& arg) {
            using T = std::decay_t<decltype(arg)>;
            if constexpr (std::is_same_v<T, int>)
                std::cout << "int with value " << arg << '\n';
            else if constexpr (std::is_same_v<T, long>)
                std::cout << "long with value " << arg << '\n';
            else if constexpr (std::is_same_v<T, double>)
                std::cout << "double with value " << arg << '\n';
            else if constexpr (std::is_same_v<T, std::string>)
                std::cout << "std::string with value " << std::quoted(arg) << '\n';
        }, w);
    }

    return 0;
}
