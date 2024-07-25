#include <map>
#include <vector>
#include <algorithm>


namespace {

auto mapped(auto num, const auto& mapping) {
    int index{ 1 };
    int mapped{};
    if (num == 0) {
        return mapping.at(num);
    }

    while (num > 0) {
        auto value{ num % 10 };
        mapped += mapping.at(value) * index;
        index *= 10;
        num /= 10;
    }
    return mapped;
}

}

class Solution {
public:
    std::vector<int> sortJumbled(const std::vector<int>& mapping, const std::vector<int>& nums) {
        std::multimap<int, int> maps;
        std::ranges::for_each(std::as_const(nums), [&](const auto& num) {
            maps.insert({mapped(num, mapping), num});
        });
        std::vector<int> result(maps.size());
        std::transform(maps.cbegin(), maps.cend(), result.begin(), [](const auto& pair) {
            return pair.second;
        });
        return result;
    }
};
