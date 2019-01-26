#include <cstdint>
#include <iostream>
#include <vector>


using i32 = int32_t;


i32 Identity(i32 n) {
    return n;
}


void PrintVector(const std::vector<i32>& v) {
    std::cout << "data: ";
    for (const auto x: v) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}


struct File {
    std::string path;
    i32 creation_timestamp{0};
};


int main() {
    i32 number = 0;
    // `auto` transforms to `i32*`
    // it's also possible to write `auto*`, i.e. `auto* number_ptr = &number_ptr;`
    auto number_ptr = &number;
    std::cout << "[number] " << number << '\n';
    std::cout << "[number_ptr] " << number_ptr << '\n';
    std::cout << "[*number_ptr] " << *number_ptr << '\n';
    *number_ptr = 1;
    std::cout << "[*number_ptr] " << *number_ptr << '\n';
    std::cout << "[Identity(*number_ptr)] " << Identity(*number_ptr) << '\n';
    std::cout << "=========================\n";

    std::vector<i32> victor = {10, 20, 30};
    // `auto` transforms to `std::vector<i32>*`
    // it's also possible to write `auto*`, i.e. `auto* victor_ptr = &victor;`
    auto victor_ptr = &victor;
    std::cout << "[victor.front()] " << victor.front() << '\n';
    std::cout << "[victor_ptr->front()] " << victor_ptr->front() << '\n';
    std::cout << "[PrintVector(victor)]\n";
    PrintVector(victor);
    std::cout << "[PrintVector(*victor_ptr)]\n";
    PrintVector(*victor_ptr);
    std::cout << "=========================\n";

    File file{"/home/ivan/tmp.txt", 123123123};
    // `auto` transforms to `File*`
    // it's also possible to write `auto*`, i.e. `auto* file_ptr = &file;`
    auto file_ptr = &file;
    std::cout << "[file.path] " << file.path << '\n';
    std::cout << "[file_ptr->path] " << file_ptr->path << '\n';
    std::cout << "=========================\n";

    std::cout << "[sizeof(number_prt)] " << sizeof(number_ptr) << '\n';
    std::cout << "[sizeof(victor_ptr)] " << sizeof(victor_ptr) << '\n';
    std::cout << "[sizeof(file_ptr)] " << sizeof(file_ptr) << '\n';

    return 0;
}
