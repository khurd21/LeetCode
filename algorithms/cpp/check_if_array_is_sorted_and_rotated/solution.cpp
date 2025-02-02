class Solution {
public:
    bool check(const std::vector<int>& nums) {
        if (nums.size() < 2) {
            return true;
        }

        std::size_t numInversions{};
        for (std::size_t index{ 1 }; index < nums.size(); ++index) {
            if (nums.at(index) < nums.at(index - 1)) {
                ++numInversions;
            }
        }
        if (nums.at(0) < nums.at(nums.size() - 1)) {
            ++numInversions;
        }
        return numInversions <= 1;
    }
};
