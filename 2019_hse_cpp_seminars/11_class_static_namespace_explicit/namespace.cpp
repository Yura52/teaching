#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <set>


using i32 = int32_t;


namespace my_std {

template<class T>
void swap(T& first, T& second) {
    const auto tmp = first;
    first = second;
    second = tmp;
}

template<class T>
class vector {
public:
    using value_type = T;

    class iterator {

    };
};

};


int main() {
    i32 a = 0;
    i32 b = 1;
    my_std::swap(a, b);
    my_std::vector<i32> v;
    my_std::vector<i32>::iterator it;
    my_std::vector<i32>::value_type x = 2;

    return 0;
}
