/* **********************************************************************
 * Link: https://leetcode.com/problems/median-of-two-sorted-arrays/
 * Author: Kyle Hurd
 * **********************************************************************
 * 
 * **********************************************************************
 * Problem: Median of Two Sorted Arrays
 * 
 * Given two sorted arrays nums1 and nums2 of size m and n respectively,
 * return the median of the two sorted arrays.
 * 
 * The overall run time complexity should be O(log (m+n)).
 * **********************************************************************
 * 
 * **********************************************************************
 * Example 1:
 * 
 * Input: nums1 = [1,3], nums2 = [2]
 * Output: 2.00000
 * Explanation: merged array = [1,2,3] and median is 2.
 * 
 * Example 2:
 * 
 * Input: nums1 = [1,2], nums2 = [3,4]
 * Output: 2.50000
 * Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 * **********************************************************************
 * 
 * **********************************************************************
 * Constraints:
 * 
 * - nums1.length == m
 * - nums2.length == n
 * - 0 <= m <= 1000
 * - 0 <= n <= 1000
 * - 1 <= m + n <= 2000
 * - -106 <= nums1[i], nums2[i] <= 10^6
 * **********************************************************************
 */

#include <vector>

class Solution {
public:
    double findMedianSortedArrays(const std::vector<int>& nums1, const std::vector<int>& nums2) {
        
        std::vector<int> merged = mergeSortedArrays(nums1, nums2);
        const int middle = merged.size() / 2;
        
        if (merged.size() % 2 == 0) {
            return (double)(merged[middle] + merged[middle - 1]) / 2;
        }
        return merged[middle];
    }

private: 

    std::vector<int> mergeSortedArrays(const std::vector<int>& arr1, const std::vector<int>& arr2) {
        
        std::vector<int> result;
        
        auto itr1 = arr1.begin();
        auto itr2 = arr2.begin();
        
        while (itr1 != arr1.end() and itr2 != arr2.end()) {
            
            if (*itr1 < *itr2) {
                result.push_back(*itr1);
                ++itr1;
            }
            else {
                result.push_back(*itr2);
                ++itr2;
            }
        }
        
        while (itr1 != arr1.end()) {
            result.push_back(*itr1);
            ++itr1;
        }
        
        while (itr2 != arr2.end()) {
            result.push_back(*itr2);
            ++itr2;
        }
        
        return result;
    }
};