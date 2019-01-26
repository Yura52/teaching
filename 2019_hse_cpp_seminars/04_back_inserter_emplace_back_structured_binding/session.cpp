#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
#include <string>
#include <vector>


using i32 = int32_t;
using Iterator = std::vector<i32>::iterator;


void Copy(Iterator src_begin, Iterator src_end, Iterator dst_begin) {
    while (src_begin != src_end) {
        *dst_begin = *src_begin;
        ++src_begin;
        ++dst_begin;
        // *dst_begin++ = *src_begin++;
    }
}


bool IsEven(i32 x) {
    return x % 2 != 0;
}


size_t FindFirstEvenIndex(const std::vector<i32>& v) {
    const auto it = std::find_if(v.begin(), v.end(), IsEven);
    return it == v.end() ? std::numeric_limits<size_t>::max() : std::distance(v.begin(), it);
}


int main() {
    std::string s = "hello";
    auto a = s.begin();
    auto b = std::next(s.begin(), 3);
    std::vector<std::string> v;
    v.push_back(std::string(a, b));
    v.emplace_back(a, b);
    std::cout << v.back() << '\n';

    return 0;
}
