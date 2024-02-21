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