#include <vector>

class Solution {
public:
    int getCommon(const std::vector<int>& nums1, const std::vector<int>& nums2) {
        auto itr1{ nums1.cbegin() };
        auto itr2{ nums2.cbegin() };
        while (itr1 < nums1.cend() && itr2 < nums2.cend()) {
            if (*itr1 == *itr2) {
                return *itr1;
            }
            *itr1 < *itr2 ? ++itr1 : ++itr2;
        }
        return -1;
    }
};