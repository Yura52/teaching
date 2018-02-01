#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <utility>

class Vector {
public:
    Vector() = default;

    ~Vector() {
        delete[] data_;
    }

    const int* data() const {
        return data_;
    }

    int* data() {
        return const_cast<int*>(const_cast<const Vector*>(this)->data());
    }

    size_t size() const {
        return size_;
    }

private:
    size_t size_{0};
    size_t capacity_{0};
    int* data_{nullptr};
};

std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    const auto size = vec.size();
    const auto data = vec.data();
    os << "size: " << size << '\n';
    for (size_t i = 0; i < size; ++ i) {
        os << data[i] << " ";
    }
    os << "\n";

    return os;
}

int main() {
    int *a = nullptr;
    delete a;
    std::cout << a << '\n';

    return 0;
}
