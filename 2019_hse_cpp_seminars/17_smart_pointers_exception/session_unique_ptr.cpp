#include <iostream>
#include <memory>
#include <utility>
#include <vector>


class UniquePtr {
public:
    UniquePtr() = default;

    UniquePtr(const UniquePtr&) = delete;

    UniquePtr(UniquePtr&& other) {
        swap(other);
    }

    UniquePtr(int* ptr) : ptr_{ptr} {}

    ~UniquePtr() {
        delete ptr_;
    }

    UniquePtr& operator=(const UniquePtr&) = delete;

    UniquePtr& operator=(UniquePtr&& other) {
        swap(other);
        return *this;
    }

    void swap(UniquePtr& other) {
        std::swap(ptr_, other.ptr_);
    }

private:
    int* ptr_{nullptr};
};


int main() {
    auto p = UniquePtr(new int(5));
    auto std_p = std::unique_ptr<int>(new int(5));
    std::cout << *std_p << '\n';
    auto q = std::move(p);

    return 0;
}
