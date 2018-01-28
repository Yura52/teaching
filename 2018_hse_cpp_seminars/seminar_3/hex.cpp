#include <ios>
#include <iostream>
#include <string>
#include <vector>

template<class C>
void PrintContainer(const C& containter, std::ostream& output_stream = std::cout) {
    for (const auto& item: containter) {
        output_stream << item << ' ';
    }
    output_stream << '\n';
}

int main() {
    std::vector<uint16_t> vec;
    uint32_t item = 0;
    while (std::cin >> std::hex >> item) {
        vec.push_back(item);
    }
    const std::string str(reinterpret_cast<const char*>(vec.data()), vec.size() * sizeof(uint16_t));
    std::cout << str << '\n';

    return 0;
}
