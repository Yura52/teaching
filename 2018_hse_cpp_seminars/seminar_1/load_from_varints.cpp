#include <cassert>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>

template<class C>
void PrintContainer(const C& containter, std::ostream& output_stream = std::cout) {
    for (const auto& item: containter) {
        output_stream << item << ' ';
    }
    output_stream << '\n';
}

uint64_t LoadOneNumber(const uint8_t* buffer, const uint8_t** shifted_buffer) {
    uint64_t number = buffer[0] & 127;
    size_t pos = 1;
    for (; buffer[pos - 1] & 128; ++pos) {
        number |= (buffer[pos] & 127) << (7 * pos);
    }
    *shifted_buffer = buffer + pos;
    return number;
}

std::vector<uint64_t> LoadNumbers(std::istream& input_stream) {
    // read all content of the stream
    const std::vector<char> stream_content(
        std::istreambuf_iterator<char>(input_stream),
        (std::istreambuf_iterator<char>())
    );
    auto buffer = reinterpret_cast<const uint8_t*>(stream_content.data());

    const auto size = LoadOneNumber(buffer, &buffer);
    std::vector<uint64_t> numbers;
    numbers.reserve(size);
    for (size_t i = 0; i < size; ++i) {
        numbers.push_back(LoadOneNumber(buffer, &buffer));
    }
    return numbers;
}

int main(const int argc, const char* argv[]) {
    // check that at least two arguments are presented
    assert(argc == 2);
    std::ifstream file{argv[1], std::ios::binary};

    const auto numbers = LoadNumbers(file);
    PrintContainer(numbers);

    return 0;
}
