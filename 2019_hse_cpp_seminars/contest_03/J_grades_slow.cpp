#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <cmath>

using i32 = int32_t;
using i64 = int64_t;

struct GradesInfo {
    i32 count{0};
    i64 total{0};
};


int main() {
    i32 grade_count = 0;
    std::cin >> grade_count;
    std::unordered_map<std::string, GradesInfo> grades;
    for (size_t i = 0; i < grade_count; ++i) {
        std::string name;
        i32 score = 0;
        std::cin >> name >> score;

        auto search = grades.find(name);
        if (search == grades.end()) {
            grades.insert({name, {1, score}});
        } else {
            ++grades[name].count;
            grades[name].total += score;
        }
        std::cout << grades[name].total / grades[name].count << '\n';
    }
    return 0;
}
