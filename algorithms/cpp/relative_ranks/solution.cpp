#include <array>
#include <string>
#include <map>
#include <vector>

namespace {

constexpr std::array scores{
    "Gold Medal",
    "Silver Medal",
    "Bronze Medal",
};

}

class Solution {
public:
    std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
        std::vector<std::string> result(score.size());
        std::map<int, int, std::greater<int>> scoreToIndex;
        for (std::size_t i{}; i < score.size(); ++i) {
            scoreToIndex.insert({score.at(i), i});
        }
        int currentScore{ 1 };
        for (const auto& [score, index] : scoreToIndex) {
            if (currentScore <= scores.size()) {
                result.at(index) = scores.at(currentScore - 1);
            }
            else {
                result.at(index) = std::to_string(currentScore);
            }
            ++currentScore;
        }
        return result;
    }
};