#include <iostream>
#include <tuple>
#include <vector>

// Compiler automatically infers when to stop this sequence end put closing triangle bracket ">";
// template<typename A0, typename A1, typename A2, ...>
// std::tuple<A0, A1, A2, ...> MakeTuple(A0 args_0, A1 args_1, A2 args_2, ...) {

// template<typename T>
// std::tuple<T> MakeSimpleTuple(T value) {
//     return std::tuple<T>(value);
// }

template<typename... Args>
std::tuple<Args...> MakeTuple(Args... args) {
    // Read it like this: [args...] ===> [args_0, args_1, args_2, ...]
    return std::tuple<Args...>(args...);
}

// Example: MakeTuple(1, 2);
// std::tuple<int, int> MakeTuple(int args_0, int args_1) {
//     return std::tuple<int, int>(args_0, args_1);
// }

template<class... Args>
std::vector<int> MakeVector(Args... args) {
    // return std::vector<int>({args_0, args_1, args_2, ...});
    return std::vector<int>({args...});
}

template<class... Args>
void Print(Args... args) {
    for (const auto x: {args...}) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

template<typename... Args>
bool All(Args... args) {
    // https://en.cppreference.com/w/cpp/language/fold
    // Unary left fold (... op E) becomes (((E1 op E2) op ......) op EN)
    return (... && args);
}

template<class... Args>
void PrintEfficiently(const Args&... args) {
    // Unary right fold (E op ...) becomes (E1 op (... op (EN-1 op EN)))
    // Here op is "operator,"
    ((std::cout << args << ' '), ...);
    std::cout << '\n';
}

int main() {
    // different calls ===> different templates' instantiation!
    const auto t1 = MakeTuple(1, 2);
    const auto t2 = MakeTuple(1, 2, 3);
    const auto v1 = MakeVector(1, 2);
    const auto v2 = MakeVector(1, 2, 3);
    Print(1, 2, 3, 4, 5);
    std::cout << std::boolalpha << All(true, true, true) << '\n';
    PrintEfficiently(1, 2, 3, 4, 5);

    return 0;
}
