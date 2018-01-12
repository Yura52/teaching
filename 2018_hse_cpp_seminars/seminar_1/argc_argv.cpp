#include <cassert>
#include <cstdint>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<uint64_t> ParseIntegers(const char* strings[], const size_t count) {
    std::vector<uint64_t> numbers;
    numbers.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        numbers.push_back(std::stoul(strings[i]));
    }
    return numbers;
}

template<class C>
void PrintContainer(const C& containter, std::ostream& output_stream = std::cout) {
    for (const auto& item: containter) {
        output_stream << item << ' ';
    }
    output_stream << "\n";
}

// argc ~ argument count
// argv ~ arguments vector
int main(const int argc, const char* argv[]) {
    // example: ./vector_serialization filename.txt 1 2 3
    // argv[0] == "vector_serialization"
    // argv[1] == "filename.txt"
    // argv[2] == "1"
    // argv[3] == "2"
    // argv[4] == "3"

    // check that at least two arguments are presented
    // NOTE: the program's name is also an argument, so "argc" is always >= 1
    assert(argc >= 2);

    const std::string path{argv[1]};
    const auto numbers = ParseIntegers(argv + 2, argc - 2);

    std::cout << path << std::endl;
    PrintContainer(numbers);

    return 0;
}
