/*
 * Given the head of a singly linked list, return true if it is a 
 * palindrome or false otherwise.
 * 
 * Example 1:
 * 
 * Input: head = [1,2,2,1]
 * Output: true
 * 
 * Example 2:
 * 
 * Input: head = [1,2]
 * Output: false
 * 
 * Constraints:
 * 
 * The number of nodes in the list is in the range [1, 105].
 * 0 <= Node.val <= 9
 * 
 * Follow up: Could you do it in O(n) time and O(1) space?
 * 
 * Yes, but didn't want to. Could do it recursively, but this is
 * still O(n) space due to the stack trace thing.
 */

#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {

        std::vector<int> v;
        while (head != nullptr) {
            v.push_back(head->val);
            head = head->next;
        }
        
        auto front{ v.begin() };
        auto back{ v.end() - 1 };

        while (front < back) {
            if (*front != *back) {
                return false;
            }
            ++front;
            --back;
        }

        return true;
    }
};