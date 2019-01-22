#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>


using i32 = int32_t;


auto MakeGoodLambda(const std::string& name) {
    std::vector<i32> v;
    return [name, v](auto x) mutable {
        std::cout << "I am lambda " << name << '\n';
        v.push_back(x);
        std::cout << "size " << v.size() << '\n';
    };
}


auto MakeBadLambda(const std::string& name) {
    std::vector<i32> v(100000000, 0);
    return [name, &v](auto x) mutable {
        std::cout << "I am lambda " << name << '\n';
        v.push_back(x);
        std::cout << "size " << v.size() << '\n';
    };
}


int main() {
    auto a = MakeGoodLambda("A");
    a(10);
    a(20);
    a(30);

    auto b = MakeGoodLambda("B");
    b(10);
    b(20);
    b(30);

    return 0;
}
