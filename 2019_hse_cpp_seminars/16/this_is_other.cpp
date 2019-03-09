#include <iostream>
#include <memory>
#include <utility>

class Vector {
public:
    Vector& operator=(const Vector& other) {
        if (this == &other) {
            return *this;
        }
        std::cout << "copy operator=\n";
        std::cout << "DELETE\n";
        std::cout << "ALLOCATION AND COPYING\n";
        // ... setting the fields correctly ...
        return *this;
    }

private:
    size_t size_{0};
    size_t capacity_{0};
    int* data_{nullptr};
};

int main() {
    

    return 0;
}
