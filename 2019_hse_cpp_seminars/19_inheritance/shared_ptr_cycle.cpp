// See also https://github.com/pytorch/pytorch/blob/master/torch/nn/parallel/scatter_gather.py#L64
#include <iostream>
#include <string>

struct B;

struct A {
    ~A() {std::cout << "A is destructed" << '\n';}
    std::shared_ptr<B> ptr;
};

struct B {
    ~B() {std::cout << "B is destructed" << '\n';}
    std::shared_ptr<A> ptr;
};

int main() {
    std::shared_ptr<A> a(new A);
    std::shared_ptr<B> b(new B);
    a->ptr = b;
    b->ptr = a;

    return 0;
}
