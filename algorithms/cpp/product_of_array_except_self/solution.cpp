#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(const std::vector<int>& nums) {
        auto prefix{ nums };
        auto suffix{ nums };

        for (std::size_t i{ 1 }; i < prefix.size(); ++i) {
            prefix[i] *= prefix[i - 1];
        }
        
        for (std::size_t i{ suffix.size() - 2}; i < suffix.size(); --i) {
            suffix[i] *= suffix[i + 1];
        }

        for (std::size_t i{}; i < prefix.size(); ++i) {
            int ans{ 1 };
            if (i != 0) {
                ans *= prefix[i - 1];
            }
            if (i != suffix.size() - 1) {
                ans *= suffix[i + 1];
            }
            suffix[i] = ans;
        }

        return suffix;
    }
};

class Solution {
public:
    std::vector<int> productExceptSelf(const std::vector<int>& nums) {

        if (nums.empty()) {
            return {};
        }

        std::vector<int> answer(nums.size());
        std::vector<int> suffix = nums;
        std::vector<int> prefix = nums;

        for (auto itr{ prefix.begin() + 1 }; itr < prefix.end(); ++itr) {
            *itr *= *(itr - 1);
        }

        for (auto itr{ suffix.rbegin() + 1 }; itr < suffix.rend(); ++itr) {
            *itr *= *(itr - 1);
        }

        *answer.rbegin() = *(prefix.rbegin() + 1);
        *answer.begin() = *(suffix.begin() + 1);

        for (int i{ 1 }; i < nums.size() - 1; ++i) {
            answer.at(i) = prefix.at(i - 1) * suffix.at(i + 1);
        }

        return answer;
    }
};