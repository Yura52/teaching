#include <iostream>
#include <memory>
#include <tuple>

template<typename T, class Deleter = std::default_delete<T>>
class UniquePtr {
public:
    UniquePtr(T* ptr, const Deleter& deleter)
        : data_{ptr, deleter}
    {}

    T* get() {
        return std::get<0>(data_);
    }

    const T* get() const {
        return std::get<0>(data_);
    }

    const Deleter& get_deleter() const {
        return std::get<1>(data_);
    }
    
    Deleter& get_deleter() {
        return std::get<1>(data_);
    }

private:
    std::tuple<T*, Deleter> data_;
};


int main() {
    std::cout << sizeof(UniquePtr<int>) << '\n';

    return 0;
}
