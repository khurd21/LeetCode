/* **********************************************************************
 * Link: https://leetcode.com/problems/remove-stones-to-minimize-the-total/
 * Author: Kyle Hurd
 * **********************************************************************
 * You are given a 0-indexed integer array piles, where piles[i]
 * represents the number of stones in the ith pile, and an integer k.
 * You should apply the following operation exactly k times:
 * 
 * Choose any piles[i] and remove floor(piles[i] / 2) stones from it.
 * Notice that you can apply the operation on the same pile more than
 * once.
 * 
 * Return the minimum possible total number of stones remaining after
 * applying the k operations.
 * 
 * floor(x) is the greatest integer that is smaller than or equal to
 * x (i.e., rounds x down).
 * 
 * Example 1:
 * 
 * Input: piles = [5,4,9], k = 2
 * Output: 12
 * Explanation: Steps of a possible scenario are:
 * - Apply the operation on pile 2. The resulting piles are [5,4,5].
 * - Apply the operation on pile 0. The resulting piles are [3,4,5].
 * 
 * The total number of stones in [3,4,5] is 12.
 * 
 * Example 2:
 * 
 * Input: piles = [4,3,6,7], k = 3
 * Output: 12
 * Explanation: Steps of a possible scenario are:
 * - Apply the operation on pile 2. The resulting piles are [4,3,3,7].
 * - Apply the operation on pile 3. The resulting piles are [4,3,3,4].
 * - Apply the operation on pile 0. The resulting piles are [2,3,3,4].
 * 
 * The total number of stones in [2,3,3,4] is 12.
 * 
 * Constraints:
 * 
 * 1 <= piles.length <= 10^5
 * 1 <= piles[i] <= 10^4
 * 1 <= k <= 10^5
 */

#include<set>
#include<queue>
#include<algorithm>
#include<numeric>

// Attempt 1: Avoided priority queue as you cannot iterate in cpp.
// This is not ideal and wasteful, we only need to know of the largest
// number in the container.

class Solution {
public:
    int minStoneSum(const std::vector<int>& piles, const int k) {

        std::multiset<int, std::greater<int>> ms{ piles.begin(), piles.end() };

        for (int i{ 0 }; i < k; ++i) {
            const auto element{ ms.cbegin() };
            const int pile{ *element - (int)*element / 2 };
            ms.erase(element);
            ms.insert(pile);
        }
        
        return std::accumulate(ms.begin(), ms.end(), 0);
    }
};

// Attempt 2: Implemented with priority queue.

class Solution {
public:
    int minStoneSum(const std::vector<int>& piles, const int k) {

        std::priority_queue<int> pq{ piles.begin(), piles.end() };
        int sum{ std::accumulate(piles.begin(), piles.end(), 0) };

        for (int i{ 0 }; i < k; ++i) {

            const int current_pile{ pq.top() };
            const int removed_pile{ (int)current_pile / 2 };
            const int new_pile{ current_pile - removed_pile };
            
            sum -= removed_pile;
            pq.pop();
            pq.push(new_pile);
        }

        return sum;
    }
};