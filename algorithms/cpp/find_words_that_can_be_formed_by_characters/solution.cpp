#include <vector>
#include <algorithm>
#include <string>

namespace {

constexpr bool isGood(const auto& word, const auto& bag) {

    auto itr{ bag.begin() };
    for (const auto c : word) {
        while (itr < bag.end() && *itr != c) {
            ++itr;
        }
        if (itr == bag.end()) {
            return false;
        }
        ++itr;
    }

    return true;
}

}

class Solution {
public:
    int countCharacters(std::vector<std::string> words, std::string chars) {

        int result{};
        std::sort(chars.begin(), chars.end());
        for (auto& word : words) {

            if (word.size() > chars.size()) {
                continue;
            }

            std::sort(word.begin(), word.end());
            if (isGood(word, chars)) {
                result += word.length();
            }
        }

        return result;
        
    }
};