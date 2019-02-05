#include <algorithm>
#include <iostream>
#include <vector>


using Iterator = std::vector<int>::iterator;


void PrintVector(const std::vector<int>& v) {
    std::cout << "data: ";
    for (const auto x: v) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}


void WriteZero(Iterator it) {
    *it = 0;
}


void WriteZero(Iterator first, Iterator last) {
    while (first != last) {
        *first = 0;
        ++first;
        // the same as two lines above
        // *first++ = 0;
    }
}

// src ~ source, dst ~ destination
void Write(Iterator src, Iterator dst_first, Iterator dst_last) {
    while (dst_first != dst_last) {
        *dst_first++ = *src;
    }
}

// src ~ source, dst ~ destination
void Copy(Iterator src_first, Iterator src_last, Iterator dst_first) {
    while (src_first != src_last) {
        *dst_first = *src_first;
        ++src_first;
        ++dst_first;
    }
}


int main() {
    std::vector<int> v = {10, 20, 30};
    std::vector<int> w(v.size(), 0);

    std::cout << "[w before copy] ";
    PrintVector(w);

    std::copy(v.begin(), v.end(), w.begin());
    std::cout << "[w after copy] ";
    PrintVector(w);

    return 0;
}
