#include <vector>
#include <numeric>

class Solution {
public:
    std::vector<int> getSumAbsoluteDifferences(const std::vector<int>& nums) {
        std::vector<int> result(nums.size(), 0);
        int rsum = std::accumulate(nums.begin(), nums.end(), 0);
        int lsum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            int num{ nums[i] };
            int rd{ num * i + rsum };
            int ld{ num * static_cast<int>(nums.size() - i) + lsum };
            result[i] = rd - ld;
            rsum -= num;
            lsum += num;
        }

        return result;
    }
};