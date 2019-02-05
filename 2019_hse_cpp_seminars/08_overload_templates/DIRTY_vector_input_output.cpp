#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>


template<class T>
std::vector<T> ReadVector(std::istream& input = std::cin) {
    return {std::istream_iterator<T>(input), std::istream_iterator<T>()};
}


int main() {
    std::vector<std::string> v(
        std::istream_iterator<std::string>(std::cin), std::istream_iterator<std::string>()
    );
    std::copy(v.begin(), v.end(), std::ostream_iterator<std::string>(std::cout, "\n"));

    return 0;
}
