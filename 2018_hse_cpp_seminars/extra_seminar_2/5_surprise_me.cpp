#include <iostream>
#include <memory>
#include <utility>
#include <vector>

class Vector {
public:
    Vector() = default;

    Vector(const Vector& other) {
        std::cout << "copy constructor\n";
        std::cout << "ALLOCATION AND COPYING\n";
    }

    Vector(Vector&& other) {
        std::cout << "move constructor\n";
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
    int* data_;
};

void SurpriseMe(Vector&& vec) {
    Vector new_vec = std::move(vec);
}

int main() {
    Vector v2;
    SurpriseMe(std::move(v2));

    return 0;
}
