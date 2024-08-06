#include <unordered_map>
#include <ranges>
#include <map>
#include <algorithm>

class Solution {
public:
    int minimumPushes(const std::string& word) {
        std::unordered_map<char, std::size_t> counts;
        std::ranges::for_each(std::as_const(word), [&](const auto character) {
            counts[character] += 1;
        });

        std::multimap<std::size_t, char, std::greater<>> mm;
        std::ranges::for_each(std::as_const(counts), [&](const auto& pair) {
            mm.insert({pair.second, pair.first});
        });

        int next_digit{}; // 7 total
        int num_presses{ 1 };
        int result{};
        std::ranges::for_each(std::as_const(mm), [&](const auto& pair) {
            const auto& count{ pair.first };
            result += num_presses * count;
            ++next_digit;
            if (next_digit > 7) {
                next_digit = 0;
                ++num_presses;
            }
        });

        return result;
    }
};
