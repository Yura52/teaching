#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>


void Foo(int x) {
    std::cout << "int " << x << '\n';
}


void Foo(double x) {
    std::cout << "double " << x << '\n';
}


void Foo(double x, double y) {
    std::cout << "double " << x << " and double " << y << '\n';
}


int Min(int a, int b) {
    return a < b ? a : b;
}


double Min(double a, double b) {
    return a < b ? a : b;
}


int main() {
    Foo(1);
    Foo(2.0);
    Foo(1, 2.0);

    return 0;
}
