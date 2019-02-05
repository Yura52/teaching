#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>


int main() {
    std::copy_if(
        std::istream_iterator<char>(std::cin), std::istream_iterator<char>(),
        std::ostream_iterator<char>(std::cout, ""),
        isdigit
    );

    return 0;
}
