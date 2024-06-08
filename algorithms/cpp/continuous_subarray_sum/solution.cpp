#include <vector>
#include <unordered_map>
#include <algorithm>

namespace {

auto prefixSumOnK(auto&& values, auto k) {
    decltype(k) prev{};
    std::ranges::for_each(values, [&prev, k](auto& value) {
        value = (value + prev) % k;
        prev = value;
    });
}

auto isGoodSubarraySum(auto&& values, auto k) {
    std::unordered_map<decltype(k), decltype(k)> map{
        { 0, -1 },
        { values.at(0) % k, 0 },
    };
    for (std::size_t i{ 1 }; i < values.size(); ++i) {
        const auto value{ values.at(i) };
        if (map.contains(value)) {
            if ((static_cast<decltype(value)>(i) - map.at(value)) > 1) {
                return true;
            }
            continue;
        }
        map[value] = static_cast<decltype(value)>(i);
    }
    return false;
}

}

class Solution {
public:
    bool checkSubarraySum(std::vector<int> nums, const int k) {
        prefixSumOnK(nums, k);
        return isGoodSubarraySum(nums, k);
    }
};