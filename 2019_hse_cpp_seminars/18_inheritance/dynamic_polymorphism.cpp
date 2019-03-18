#include <iostream>
#include <memory>
#include <deque>

class A {
public:
    virtual std::string GetName() const = 0;
};

class B : public A {
public:
    std::string GetName() const override {
        return "B";
    }
};

class C : public A {
public:
    std::string GetName() const override {
        return "C";
    }
};

void Print(const A& x) {
    std::cout << x.GetName() << '\n';
}

int main() {    
    Print(B());
    Print(C());

    return 0;
}
