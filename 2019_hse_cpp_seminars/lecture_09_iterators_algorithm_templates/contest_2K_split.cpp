#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
#include <string>


std::vector<std::string> Split(const std::string& str, char delimiter) {
    std::vector<std::string> string_parts;
    auto part_begin = str.cbegin();
    auto part_end = std::find(
        str.cbegin(), str.cend(), delimiter
    );

    while (part_end != str.cend()) {
        string_parts.emplace_back(part_begin, part_end);
        part_begin = std::next(part_end);
        part_end = std::find(
            part_begin, str.cend(), delimiter
        );
    }
    string_parts.emplace_back(part_begin, part_end);

    return string_parts;
}


int main() {
    std::string s;
    char d{0};
    std::cin >> s >> d;
    for (const auto& x: Split(s, d)) {
        std::cout << x << '\n';
    }

    return 0;
}
