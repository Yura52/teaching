#include <iostream>
#include <utility>

class Vector {
public:
    Vector() = default;

    ~Vector() {
        std::cout << "delete memory\n";
    }

    Vector(const Vector& other) {
        std::cout << "copy constructor\n";
        *this = other;
    }

    Vector(Vector&& other) {
        std::cout << "move constructor\n";
        *this = std::move(other);
    }

    Vector& operator=(const Vector& other) {
        std::cout << "copy operator=\n";
        std::cout << "ALLOCATION AND COPYING\n";
        return *this;
    }

    Vector& operator=(Vector&& other) {
        std::cout << "move operator=\n";
        swap(other);
        return *this;
    }

    void swap(Vector& other) {
        std::cout << "swap\n";
        std::swap(data_, other.data_);
        std::swap(size_, other.size_);
        std::swap(capacity_, other.capacity_);
    }

private:
    size_t size_{0};
    size_t capacity_{0};
    int* data_{nullptr};
};

Vector BuildHeavyVector() {
    return Vector();
}

int main() {
    Vector v1;
    Vector v2(v1);
    Vector v3;
    v3 = BuildHeavyVector();
    v1 = std::move(v3);

    return 0;
}
