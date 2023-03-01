/*
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n))
time complexity and with the smallest space complexity possible.

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not
changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessarily unique.
 

Constraints:

1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104
*/

#include <vector>
#include <random>

class Solution {
public:
    std::vector<int> sortArray(const std::vector<int>& nums) {
        std::vector<int> result(nums);

        if (is_sorted(result)) {
            return result;
        }

        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(result.begin(), result.end(), g);

        this->quick_sort(result, 0, nums.size() - 1);
        return result;
    }

    bool is_sorted(const std::vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i-1] > nums[i]) {
                return false;
            }
        }
        return true;
    }

    void quick_sort(std::vector<int>& nums, const int lo, const int hi) {
        if (lo >= hi || lo < 0) {
            return;
        }
        const int partition{ this->partition(nums, lo, hi) };
        this->quick_sort(nums, lo, partition - 1);
        this->quick_sort(nums, partition + 1, hi);
        return;
    }

    int partition(std::vector<int>& nums, const int lo, const int hi) {
        const int pivot{ nums[hi] };
        int i{ lo - 1 };
        for (int j = lo; j < hi; ++j) {
            if (nums[j] <= pivot) {
                ++i;
                std::swap(nums[i], nums[j]);
            }
        }
        ++i;
        std::swap(nums[i], nums[hi]);
        return i;
    }
};