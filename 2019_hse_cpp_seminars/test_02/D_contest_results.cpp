#include <map>
#include <string>
#include <vector>

using i32 = int32_t;
using ContestResult = std::map<std::string, i32>;

std::map<std::string, i32> final_standings(
    const std::vector<ContestResult>& results
) {
    ContestResult final_result;
    for (const auto& contest_result : results) {
        for (const auto& [login, score] : contest_result) {
            const auto [it, was_inserted] = final_result.insert({login, score});
            if (!was_inserted) {
                it->second = std::max(it->second, score);
            }
        }
    }
    return final_result;
}
