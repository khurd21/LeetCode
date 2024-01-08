#include <vector>
#include <map>
#include <cstdint>

namespace {

struct Slice {

    std::uint64_t diff;
    int index;

}; // struct Slice

bool operator<(const Slice& lhs, const Slice& rhs) {
    return std::tie(lhs.diff, lhs.index) < std::tie(rhs.diff, rhs.index);
}

} // namespace

class Solution {
public:
    int numberOfArithmeticSlices(std::vector<int>& nums) {
        int result{};

        std::map<Slice, int> dp;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                const auto diff{ static_cast<std::uint64_t>(nums[i]) - nums[j] };
                dp[{diff, i}] += 1;
                if (dp.contains({diff, j})) {
                    dp[{diff, i}] += dp[{diff, j}];
                    result += dp[{diff, j}];
                }
            }
        }

        return result;
    }

};