#include <cassert>
#include <cstdint>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<uint64_t> ParseNumbers(const char* strings[], const size_t count) {
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
    output_stream << '\n';
}

void DumpNumbers(const std::vector<uint64_t>& numbers, std::ostream& output_stream) {
    output_stream << numbers.size() << ' ';
    PrintContainer(numbers, output_stream);
}

int main(const int argc, const char* argv[]) {
    // check that at least two arguments are presented
    assert(argc >= 2);
    std::ofstream file{argv[1]};
    const auto numbers = ParseNumbers(argv + 2, argc - 2);

    DumpNumbers(numbers, file);

    return 0;
}
