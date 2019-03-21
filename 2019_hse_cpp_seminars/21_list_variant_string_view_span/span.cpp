#include <cstdint>
#include <iostream>
#include <span>

using i32 = int32_t;

void ScanVector(
    const std::vector<i32>& v,
    const std::function<void(std::span<i32>)>& callback
) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] == 0) {
            callback({v.data() + left_index, v.data() + i});
            left_index = i + 1;
        }
    }
}

int main() {
    std::vector<int> v = {1, 2, 3, 0, 1, 2 3, 4, 5, 0, 1};
    ScanVector(v, [](std::span<i32> s) {
        std::cout << s.size() << '\n';
    });
    
    return 0;
}
