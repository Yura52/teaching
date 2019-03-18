#include <iostream>
#include <memory>
#include <deque>

class A {
public:
    A() {
        std::cout << GetName() << " CONSTRUCTOR\n";
    }

    ~A() {
        std::cout << GetName() << " DESTRUCTOR\n";
    }

    virtual std::string GetName() const {
        return "A";
    }
};

class B : public A {
public:
    std::string GetName() const override {
        return "B";
    }
};

int main() {
    int a = 0;
    std::cin >> a;
    const std::unique_ptr<A> p = a ? std::make_unique<A>() : std::make_unique<B>();

    return 0;
}
