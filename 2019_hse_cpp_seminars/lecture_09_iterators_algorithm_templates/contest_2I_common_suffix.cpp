#include <algorithm>
#include <iostream>
#include <string>


std::string CommonSuffix(const std::string& a, const std::string& b) {
    const auto mismatch_iterators = std::mismatch(
        a.rbegin(), a.rend(),
        b.rbegin(), b.rend()
    );
    const auto suffix_size = std::distance(
        a.rbegin(), mismatch_iterators.first
    );
    std::string suffix(suffix_size, 0);
    std::reverse_copy(
        a.rbegin(), std::next(a.rbegin(), suffix_size),
        suffix.begin()
    );
    return suffix;
}


int main() {
    std::string a, b;
    std::cin >> a >> b;
    std::cout << CommonSuffix(a, b) << '\n';

    return 0;
}
