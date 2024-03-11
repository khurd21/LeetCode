#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<int> intersection(const std::vector<int>& nums1, const std::vector<int>& nums2) {
        std::unordered_set<int> s1(nums1.cbegin(), nums1.cend());
        std::unordered_set<int> result_set;
        for (const auto num : nums2) {
            if (s1.contains(num)) {
                result_set.insert(num);
            }
        }
        return std::vector<int>(result_set.cbegin(), result_set.cend());
    }
};