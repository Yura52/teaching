#include <iostream>
#include <tuple>
#include <vector>

// Compiler automatically infers when to stop this sequence end put closing triangle bracket ">";
// template<typename A1, typename A2, typename A3, ...>
// std::tuple<A1, A2, A3, ...> MakeTuple(A1 args_1, A2 args_2, A3 args_3, ...) {

// template<typename T>
// std::tuple<T> MakeSimpleTuple(T value) {
//     return std::tuple<T>(value);
// }

template<typename... Args>
std::tuple<Args...> MakeTuple(Args... args) {
    // Read it like this: [args...] ===> [args_1, args_2, args_3, ...]
    return std::tuple<Args...>(args...);
}

// Example: MakeTuple(1, 2);
// std::tuple<int, int> MakeTuple(int args_1, int args_2) {
//     return std::tuple<int, int>(args_1, args_2);
// }

template<class... Args>
std::vector<int> MakeVector(Args... args) {
    // return std::vector<int>({args_1, args_2, args_3, ...});
    return std::vector<int>({args...});
}

template<class... Args>
void Print(Args... args) {
    for (const auto x: {args...}) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

int main() {
    // different calls ===> different templates' instantiation!
    const auto t1 = MakeTuple(1, 2);
    const auto t2 = MakeTuple(1, 2, 3);
    const auto v1 = MakeVector(1, 2);
    const auto v2 = MakeVector(1, 2, 3);
    Print(1, 2, 3, 4, 5);

    return 0;
}
