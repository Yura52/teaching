#include <algorithm>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using i32 = int32_t;


std::vector<i32> GetUnsolvedProblems(
    i32 problem_count, const std::vector<i32>& solved_problems
) {
    std::vector<i32> all_problems(problem_count, 0);
    std::iota(all_problems.begin(), all_problems.end(), 0);
    std::vector<i32> unsolved_problems;
    std::set_difference(
        all_problems.begin(), all_problems.end(),
        solved_problems.begin(), solved_problems.end(),
        std::back_inserter(unsolved_problems)
    );
    return unsolved_problems;
}


int main() {
    i32 contest_id = 0;
    while (std::cin >> contest_id) {
        i32 problem_count = 0;
        std::cin >> problem_count;

        std::vector<int> solved_problems;
        auto letters_are_used = false;
        for (auto x = std::getchar(); x == ' '; x = std::getchar()) {
            std::string s;
            std::cin >> s;
            letters_are_used = isalpha(s.front());
            solved_problems.push_back(letters_are_used ? s.front() - 'A': std::stoi(s) - 1);
        }
        const auto unsolved_problems = GetUnsolvedProblems(problem_count, solved_problems);

        std::cout << contest_id;
        for (const auto x : unsolved_problems) {
            std::cout << ' ';
            if (letters_are_used) {
                std::cout << static_cast<char>(x + 'A');
            } else {
                std::cout << x + 1;
            }
        }
        std::cout << '\n';
    }

    return 0;
}
