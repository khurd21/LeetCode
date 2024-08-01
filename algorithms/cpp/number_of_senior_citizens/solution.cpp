#include <vector>
#include <algorithm>
#include <ranges>

class Solution {
public:
    int countSeniors(const std::vector<std::string>& details) {
        return std::ranges::count_if(std::as_const(details), [](const auto& detail) {
            const auto age{ std::stoi(detail.substr(11, 2)) };
            return age > 60;
        });
    }
};
