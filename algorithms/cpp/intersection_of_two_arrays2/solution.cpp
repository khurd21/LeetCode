#include <vector>
#include <set>

class Solution {
public:
    std::vector<int> intersect(const std::vector<int> &nums1, const std::vector<int> &nums2) {
        auto result{nums2};
        std::multiset ms(nums1.cbegin(), nums1.cend());
        result.erase(std::remove_if(result.begin(), result.end(), [&](const auto &num) {
            const auto contains{ ms.contains(num) };
            if (contains) {
                ms.extract(num);
            }
            return !contains;
        }), result.end());
        return result;
    }
};
