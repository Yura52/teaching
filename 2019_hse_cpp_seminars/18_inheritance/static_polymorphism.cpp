#include <iostream>
#include <memory>
#include <deque>

class B {
public:
    std::string GetName() const {
        return "B";
    }
};

class C {
public:
    std::string GetName() const {
        return "C";
    }
};

template<typename T>
void Print(const T& x) {
    std::cout << x.GetName() << '\n';
}

int main() {    
    Print(B());
    Print(C());

    return 0;
}
