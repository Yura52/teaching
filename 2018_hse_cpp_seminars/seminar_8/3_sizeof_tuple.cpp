#include <iostream>
#include <utility>
#include <tuple>

struct A {};

class B {
    A a;
};

int main() {
    std::cout << "sizeof(A) == " << sizeof(A) << '\n';
    std::cout << "sizeof(B) == " << sizeof(B) << '\n';
    std::cout << "sizeof(std::pair<int, A>) == " << sizeof(std::pair<int, A>) << '\n';
    std::cout << "sizeof(std::pair<int, B>) == " << sizeof(std::pair<int, B>) << '\n';
    std::cout << "sizeof(std::tuple<int, A>) == " << sizeof(std::tuple<int, A>) << '\n';
    std::cout << "sizeof(std::tuple<int, B>) == " << sizeof(std::tuple<int, B>) << '\n';

    return 0;
}
