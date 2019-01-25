#include <cstdint>
#include <iostream>
#include <map>
#include <vector>

// ContestResults: login --> scores
using ContestResults = std::map<std::string, std::vector<int32_t>>;


// Examples:
// const auto contest_count = Read<size_t>();
// const auto login = Read<std::string>();
template<typename T>
T Read() {
    T value;
    std::cin >> value;
    return value;
}

void InsertScore(
    const std::string& login,
    const int32_t score,
    const size_t contest_index,
    const size_t contest_count,
    ContestResults& results);

void ReadOneContestResult(
    size_t student_count,
    const size_t contest_index,
    const size_t contest_count,
    ContestResults& results);

ContestResults ReadContestResults(const size_t contest_count);

void PrintContestResults(const ContestResults& results);

int main() {
    const auto contest_count = Read<size_t>();
    const auto contest_results = ReadContestResults(contest_count);
    PrintContestResults(contest_results);

    return 0;
}
