#include <algorithm>
#include <iostream>
#include <string>


std::string ExtractDigits(const std::string& s) {
    std::string digits;
    std::copy_if(
        s.begin(), s.end(), std::back_inserter(digits), isdigit
    );
    return digits;
}


int main() {
    std::string s;
    std::cin >> s;
    std::cout << ExtractDigits(s) << '\n';
    return 0;
}
