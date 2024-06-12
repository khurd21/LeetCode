#include <vector>

namespace {

template <typename Iter>
void sortColors(Iter begin, Iter end) {
    // Partitioning into distinct groups
    auto low{ begin };
    auto middle{ begin };
    auto high{ end - 1 };
    while (middle <= high) {
        if (*middle == 0) {
            std::swap(*middle, *low);
            ++low;
            ++middle;
        }
        else if (*middle == 1) {
            ++middle;
        }
        else {
            std::swap(*middle, *high);
            --high;
        }
    }
}

}


class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        ::sortColors(nums.begin(), nums.end());
    }
};