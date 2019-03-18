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

template<typename T>
using Ptr = std::unique_ptr<T>;

int main() {
    // A a;
    // std::cout << a.GetName() << '\n';
    // B b;
    // std::cout << b.GetName() << '\n';

    // A a;
    // std::cout << a.GetName() << '\n';
    // A b = B();
    // std::cout << b.GetName() << '\n';

    // Ptr<A> a = std::make_unique<A>();
    // std::cout << a->GetName() << '\n';
    // Ptr<B> b = std::make_unique<B>();
    // std::cout << b->GetName() << '\n';

    // Ptr<A> a = std::make_unique<A>();
    // std::cout << a->GetName() << '\n';
    // Ptr<A> b = std::make_unique<B>();
    // std::cout << b->GetName() << '\n';

    // std::deque<A> v = {A(), B(), C()};
    // for (const auto& x : v) {
    //     std::cout << x.GetName() << '\n';
    // }

    // std::deque<Ptr<A>> v = {
    //     std::make_unique<A>(),
    //     std::make_unique<B>(),
    //     std::make_unique<C>(),
    // };
    // for (const auto& x : v) {
    //     std::cout << x.GetName() << '\n';
    // }

    return 0;
}
