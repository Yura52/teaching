#include <iostream>
#include <string_view>

size_t BadLengthWithExtraCopy(const std::string& s) {
    return s.size();
}

size_t Length(std::string_view s) {
    return s.size();
}

int main() {
    const std::string s = "AAAA BBBBBBB CC";

    size_t left_index = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
            std::cout
                << Length({s.data() + left_index, i - left_index})
                << '\n';
            left_index = i + 1;
        }
    }
    std::cout
        << Length({s.data() + left_index, s.size() - left_index})
        << '\n';
    
    return 0;
}
