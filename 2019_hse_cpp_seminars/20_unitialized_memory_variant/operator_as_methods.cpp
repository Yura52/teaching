#include <iostream>

struct A {
    void operator[](int x) {
        std::cout << x << '\n';
    }
};

int main() {
    A a;
    a.operator[](123);

    return 0;
}
