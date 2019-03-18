#include <iostream>
#include <memory>

struct Data {
    ~Data() {
        std::cout << "DATA DESTRUCTOR\n";
    }
};

class A {
public:
    // Try to switch between virtual/nonvirtual destructor and see what changes
    // virtual ~A() {
    ~A() {
        std::cout << "A DESTRUCTOR\n";
    }
};

class B : public A {
public:
    ~B() {
        std::cout << "B DESTRUCTOR\n";
    }

private:
    Data data_;
};

int main() {
    int a = 0;
    std::cin >> a;
    const std::unique_ptr<A> ptr = a ? std::make_unique<B>() : std::make_unique<A>();
    return 0;
}
