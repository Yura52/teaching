#include <iostream>
#include <string>

struct B;

struct A {
    ~A() {std::cout << "A is destructed" << std::endl;}
    std::shared_ptr<B> ptr;
};

struct B {
    ~B() {std::cout << "B is destructed" << std::endl;}
    std::shared_ptr<A> ptr;
};

int main() {
    // delete won't be called
    std::shared_ptr<A> a(new A);
    std::shared_ptr<B> b(new B);
    a->ptr = std::shared_ptr<B>(b);
    b->ptr = std::shared_ptr<A>(a);

    return 0;
}
