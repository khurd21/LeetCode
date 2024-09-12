#include <unordered_set>
#include <ranges>
#include <string>
#include <vector>

class Solution {
public:
    int countConsistentStrings(const std::string& allowed, const std::vector<std::string>& words) {
        int result{};
        std::unordered_set<char> s(allowed.cbegin(), allowed.cend());
        std::ranges::for_each(std::as_const(words), [&](const auto& word) {
            const auto isConsistent{ std::ranges::all_of(std::as_const(word), [&](const auto character) {
                return s.contains(character);
            }) };
            result += static_cast<int>(isConsistent);
        });
        return result;
    }
};
