#include <iostream>
#include <string>

class Base {
public:
    explicit Base(const std::string& str) : base_field{str} {}
    std::string base_field;
};

class Derived : public Base {
public:
    explicit Derived(const std::string& str) : Base{str} {}

    std::string derived_field;
};

void Print(const Base* base_ptr) {
    std::cout << base_ptr << ' ' << base_ptr->base_field << '\n';
}

void Print(const Base& base) {
    std::cout << &base << ' ' << base.base_field << '\n';
}

int main() {
    const Base base{"Hello, Base!"};
    const Derived derived{"Hello, Derived!"};
    Print(&base);
    Print(&derived);
    Print(base);
    Print(derived);

    return 0;
}
