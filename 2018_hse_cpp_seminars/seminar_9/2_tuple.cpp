#include <iostream>
#include <string>

template<typename... Args>
class Tuple;

template<typename T>
class Tuple<T> {
public:
    Tuple(T value) : head_{value} {}

private:
    T head_;
};

template<typename T, typename... Args>
class Tuple<T, Args...> {
public:
    Tuple(T value, Args... args) : head_{value}, tail_(args...) {}

private:
    T head_;
    Tuple<Args...> tail_;
};

int main() {
    Tuple<int, double, std::string> t(1, 2.0, "hello");

    return 0;
}
