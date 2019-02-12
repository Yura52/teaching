#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using i32 = int32_t;

// 2D
template<class ForwardIterator, class Predicate>
ForwardIterator FindIf(
    ForwardIterator first,
    ForwardIterator last,
    Predicate predicate
) {
    for (auto it = first; it != last; ++it) {
        if (predicate(*it)) {
            return it;
        }
    }
    return last;
}

// 3A
struct Less3A {
    bool operator()(i32 first, i32 second) {
        return first < second;
    }
};
void Example3A() {
    Less3A comparator;
    std::cout << (comparator(1, 2) ? "less" : "greater or equal") << '\n';
}

// 3B
struct Less3B {
    template<class T>
    bool operator()(const T& first, const T& second) {
        return first < second;
    }
};
// Example of usage: the same as in 3A

// 3C
template<class T>
struct Less3C {
    bool operator()(const T& first, const T& second) {
        return first < second;
    }
};
void Example3C() {
    Less3C<i32> comparator_1;
    std::cout
        << (comparator_1(1, 2) ? "less" : "greater or equal")
        << '\n';
    Less3C<std::string> comparator_2;
    std::cout
        << (comparator_2("hello", "world") ? "less" : "greater or equal")
        << '\n';
}

// 4E
template<class RandomIterator, class Comparator = Less3B
void Sort(
    RandomIterator first,
    RandomIterator last,
    Comparator comparator = {}
) {
    std::sort(first, second, comparator);
}


int main() {
    std::vector<i32> v = {4, 3, 2, 1};

    Sort(v.begin(), v.end());
    for (auto x: v) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    Sort(
        v.begin(), v.end(),
        [](auto first, auto second){ return first > second; }
    );
    for (auto x: v) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    return 0;
}
