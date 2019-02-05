#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>


using i32 = int32_t;


int main() {
    std::vector<i32> v = {30, 20, 10};
    // std::vector<i32>::iterator;
    std::sort(v.begin(), v.end());

    std::vector<std::string> w = {"a", "b", "c"};
    // std::vector<std::string>::iterator;
    std::sort(w.begin(), w.end());

    return 0;
}
