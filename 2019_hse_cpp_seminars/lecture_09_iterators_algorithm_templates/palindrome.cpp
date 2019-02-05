#include <algorithm>
#include <iostream>
#include <string>


int main() {
    std::string s = "HELLO OLLEH";
    std::cout << std::boolalpha;
    std::cout << std::equal(s.begin(), s.end(), s.rbegin());

    return 0;
}
