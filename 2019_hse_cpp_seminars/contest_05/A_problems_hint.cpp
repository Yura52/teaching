#include <algorithm>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using i32 = int32_t;

std::vector<i32> GetUnsolvedProblems(i32 problem_count, const std::vector<i32>& solved_problems);

int main() {
    i32 contest_id = 0;
    while (std::cin >> contest_id) {
        // read problem_count
        // ...
        for (auto x = std::getchar(); x == ' '; x = std::getchar()) {
            // you don't need to use `x`, it is needed only for the loop
            // ...
        }
        // `solved_problems` and `unsolved_problems` are both vectors of zero-based task ids
        const auto unsolved_problems = GetUnsolvedProblems(problem_count, solved_problems);

        // output
    }

    return 0;
}
