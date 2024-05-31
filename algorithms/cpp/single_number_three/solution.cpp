#include <algorithm>
#include <numeric>
#include <vector>

namespace {

auto getFirstNonZero(const auto num) {
    int i{};
    while (((num >> i) & 1) == 0) {
        ++i;
    }
    return i;
}

}

class Solution {
public:
    std::vector<int> singleNumber(const std::vector<int>& nums) {
        const auto exclusives{ std::accumulate(nums.cbegin(), nums.cend(), 0, std::bit_xor<>()) };
        const auto i{ getFirstNonZero(exclusives) };
        std::vector<int> result(2);
        std::ranges::for_each(nums, [&](const auto num) {
            result.at(static_cast<int>((num >> i) & 1)) ^= num;
        });
        return result;
    }
};