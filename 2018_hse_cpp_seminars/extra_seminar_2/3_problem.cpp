#include <iostream>
#include <memory>
#include <utility>

class Vector {
public:
    Vector() = default;

    Vector(const Vector& other) {
        std::cout << "copy constructor\n";
        *this = other;
    }

    Vector& operator=(const Vector& other) {
        std::cout << "copy operator=\n";
        // std::cout << "ALLOCATION AND COPYING\n";
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = other.data_;
        return *this;
    }

private:
    size_t size_{0};
    size_t capacity_{0};
    int* data_{nullptr};
};

Vector BuildVector() {
    return Vector();
}

int main() {
    Vector v1;
    Vector v2(v1);
    Vector v3;
    v3 = std::move(BuildVector());

    return 0;
}
