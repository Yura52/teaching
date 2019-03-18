#include <deque>
#include <iostream>
#include <memory>
#include <string>

class A {
public:
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

template<typename T>
using Ptr = std::unique_ptr<T>;

Ptr<A> Make(const std::string& s) {
    return
        s == "A" ? std::make_unique<A>() :
        s == "B" ? std::make_unique<B>() :
        nullptr;
}

int main() {
    std::cout << sizeof(A) << ' ' << sizeof(B) << "\n\n";

    std::string s;
    std::cin >> s;
    auto p_ptr = Make(s);
    std::cin >> s;
    auto q_ptr = Make(s);

    auto& p = *p_ptr;
    auto& q = *q_ptr;

    std::cout << p.GetName() << '\n';
    std::cout << q.GetName() << '\n';

    *reinterpret_cast<size_t*>(&p) = *reinterpret_cast<size_t*>(&q);
    std::cout << p.GetName() << '\n';
    std::cout << q.GetName() << '\n';

    return 0;
}
