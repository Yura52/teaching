#include <algorithm>
#include <cctype>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>


bool IsVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}


std::pair<size_t, size_t> FindVowels(
    const std::string& text, size_t pos
) {
    const auto first = std::find_if(
        std::next(text.cbegin(), pos),
        text.cend(),
        IsVowel
    );
    if (first == text.end()) {
        return {std::string::npos, 0};
    }
    const auto last = std::find_if_not(
        first, text.end(), IsVowel
    );
    return {std::distance(text.cbegin(), first), std::distance(first, last)};
}


int main() {
    std::string text;
    std::getline(std::cin, text);
    size_t pos = 0;
    while (true) {
        auto [start, length] = FindVowels(text, pos);
        if (start == std::string::npos)
            break;
        std::cout << start << " " << length << " " << text.substr(start, length) << "\n";
        pos = start + length;
    }
}
