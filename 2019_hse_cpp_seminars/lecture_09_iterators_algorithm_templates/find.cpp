#include <algorithm>
#include <iostream>
#include <vector>


using Iterator = std::vector<int>::iterator;


Iterator Find(Iterator first, Iterator last, int value) {
    for (; first != last; ++first) {
        if (*first == value) {
            return first;
        }
    }
}


int main() {

    return 0;
}
