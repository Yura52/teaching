#include <iostream>
#include <stdexcept>

void foo() {
    try {
        throw std::runtime_error(":(");
    } catch (const std::runtime_error& err) {
        std::cout << &err << '\n';
        // `throw;` means "rethrow current exception"
        throw;
    }
}

int main() {
    try {
        foo();
    } catch (const std::runtime_error& err) {
        // The same address as above, because we catched the same exception object, because
        // it was rethrown via `throw;`
        std::cout << &err << '\n';
        return 0;
    }

    return 0;
}
