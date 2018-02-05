#include <cstdint>
#include <iostream>
#include <map>
#include <vector>

using ContestResults = std::map<std::string, std::vector<int32_t>>;

template<typename T>
T Read(std::istream& is = std::cin) {
    T value;
    is >> value;
    return value;
}

void InsertScore(
    const std::string& login,
    const int32_t score,
    const size_t contest_index,
    const size_t contest_count,
    ContestResults* results)
{
    auto& student_scores = (*results)[login];
    if (student_scores.empty()) {
        student_scores.resize(contest_count, 0);
    }
    student_scores[contest_index] = score;
}

void ReadOneContestResult(
    size_t student_count,
    const size_t contest_index,
    const size_t contest_count,
    ContestResults* results)
{
    while (student_count > 0) {
        const auto login = Read<std::string>();
        const auto score = Read<int32_t>();
        InsertScore(login, score, contest_index, contest_count, results);

        --student_count;
    }
}

ContestResults ReadContestResults(const size_t contest_count) {
    ContestResults results;
    for (size_t contest_index = 0; contest_index < contest_count; ++contest_index) {
        const auto student_count = Read<size_t>();
        ReadOneContestResult(student_count, contest_index, contest_count, &results);
    }
    return results;
}

void PrintStudentResult(const ContestResults::value_type& student_result, std::ostream& os) {
    os << student_result.first << '\t';
    for (const auto score: student_result.second) {
        os << score << '\t';
    }
    os << '\n';
}

void PrintContestResults(const ContestResults& results, std::ostream& os = std::cout) {
    for (const auto& student_result: results) {
        PrintStudentResult(student_result, os);
    }
}

int main() {
    const auto contest_count = Read<size_t>();
    const auto contest_results = ReadContestResults(contest_count);
    PrintContestResults(contest_results);

    return 0;
}
