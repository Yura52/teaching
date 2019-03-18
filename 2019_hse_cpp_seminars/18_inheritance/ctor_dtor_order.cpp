#include <iostream>

class A {
public:
    A() {
        std::cout << "A()\n";
    }

    ~A() {
        std::cout << "~A()\n";
    }
};

class B {
public:
    B() {
        std::cout << "B()\n";
    }

    ~B() {
        std::cout << "~B()\n";
    }

private:
    A a_;
};

class C : public B {
public:
    C() {
        std::cout << "С()\n";
    }

    ~C() {
        std::cout << "~С()\n";
    }
};


int main() {
    C c;

    return 0;
}
