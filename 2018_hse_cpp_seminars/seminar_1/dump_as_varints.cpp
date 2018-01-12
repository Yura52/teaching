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

void DumpOneNumber(uint64_t number, std::vector<uint8_t>* buffer) {
    // While more than 7 bits of data are left
    while (number > 127) {
        // "|128" sets the "next byte flag"
        const uint8_t byte = static_cast<uint8_t>(number & 127) | 128;
        buffer->push_back(byte);
        // Remove the seven bits we've just wrote
        number >>= 7;
    }
    // NOTE: here we don't set the "next byte flag"
    const uint8_t byte = static_cast<uint8_t>(number & 127);
    buffer->push_back(byte);
}

void DumpNumbers(const std::vector<uint64_t>& numbers, std::ostream& output_stream) {
    std::vector<uint8_t> buffer;
    DumpOneNumber(numbers.size(), &buffer);
    for (const auto number: numbers) {
        DumpOneNumber(number, &buffer);
    }
    output_stream.write(reinterpret_cast<const char*>(buffer.data()), buffer.size());
}

int main(const int argc, const char* argv[]) {
    // check that at least two arguments are presented
    assert(argc >= 2);
    std::ofstream file{argv[1], std::ios::binary};
    const auto numbers = ParseNumbers(argv + 2, argc - 2);
    DumpNumbers(numbers, file);

    return 0;
}
