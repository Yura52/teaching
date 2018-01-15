#include <iostream>
#include <memory>

void CustomIntegerDeleter(int* ptr) {
    std::cout << "I am a function!\n";
    delete ptr;
}

int main() {
    std::unique_ptr<int, decltype((CustomIntegerDeleter))> fptr(new int{0}, CustomIntegerDeleter);

    auto custom_deleter = [](auto* ptr) {
        std::cout << "I am a lambda!\n";
        delete ptr;
    };

    std::unique_ptr<int, decltype(custom_deleter)> lptr(new int{0}, custom_deleter);

    std::cout << "fptr size: " << sizeof(fptr) << '\n';
    std::cout << "lptr size: " << sizeof(lptr) << '\n';

    return 0;
}

// For details see the item 4.1 in "Effective modern C++" by Scott Meyers
