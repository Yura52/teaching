#include <iostream>
#include <memory>


class SharedPtr {
public:
    SharedPtr() = default;

    SharedPtr(int* ptr) : ptr_{ptr} {
        std::unique_ptr<int> uptr{ptr};
        counter_ = new size_t(1);
        uptr.release();
    }

    SharedPtr(SharedPtr& other)
        : ptr_{other.ptr_}, counter_{other.counter_}
    {
        ++*counter_;
    }

    void Release() {
        if (*counter_ == 1) {
            delete ptr_;
            delete counter_;
        } else {
            --*counter_;
        }
    }

    ~SharedPtr() {
        Release();
    }

    SharedPtr& operator=(SharedPtr& other) {
        if (this == &other) {
            return *this;
        }
        Release();
        ptr_ = other.ptr_;
        counter_ = other.counter_;
        ++*counter_;
        return *this;
    }

private:
    int* ptr_{nullptr};
    size_t* counter_{nullptr};
};


int main() {
    auto p = SharedPtr(new int(5));
    auto q = SharedPtr(new int(6));
    p = q;

    return 0;
}
