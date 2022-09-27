/* **********************************************************************
 * Link: https://leetcode.com/problems/add-two-numbers/
 * Author: Kyle Hurd
 * **********************************************************************
 * 
 * **********************************************************************
 * Problem: Add Two Numbers
 * 
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order, and each of their
 * nodes contains a single digit. Add the two numbers and return the sum
 * as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero,
 * except the number 0 itself.
 * **********************************************************************
 * 
 * **********************************************************************
 * Example 1:
 * 
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 * 
 * Example 2:
 * 
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 * 
 * Example 3:
 * 
 * Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * Output: [8,9,9,9,0,0,0,1]
 * **********************************************************************
 * 
 * **********************************************************************
 * Constraints:
 * 
 * - The number of nodes in each linked list is in the range [1, 100].
 * - 0 <= Node.val <= 9
 * - It is guaranteed that the list represents a number that does not
 *   have leading zeros.
 * **********************************************************************
 * Definition for singly-linked list:
 * 
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 * **********************************************************************
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        bool carry = false;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        
        int num = p1->val + p2->val;
        if (num >= 10) {
            carry = true;
            num -= 10;
        }
        
        ListNode* result = new ListNode;
        result->val = num;
        result->next = nullptr;
        ListNode* currentPtr = result;
        
        p1 = p1->next;
        p2 = p2->next;
        
        while (p1 != nullptr && p2 != nullptr) {
            // perform the operation -- add p1 + p2 to result
            int num = p1->val + p2->val + (int)carry;
            carry = false;
            
            if (num >= 10) {
                carry = true;
                num -= 10;
            }
            
            ListNode* tmpPtr = new ListNode;
            tmpPtr->val = num;
            tmpPtr->next = nullptr;
            
            currentPtr->next = tmpPtr;
            currentPtr = currentPtr->next;
            
            p1 = p1->next;
            p2 = p2->next;
        }
        
        if (p1 == nullptr && p2 == nullptr) {
            if (carry == true) {
                ListNode* tmp = new ListNode;
                tmp->val = (int)carry;
                tmp->next = nullptr;
                currentPtr->next = tmp;
                currentPtr = currentPtr->next;
            }
            return result;
        }
        else {
            appendLastElements(currentPtr, (p1 == nullptr) ? p2 : p1, carry);
            return result;
        }
    }
    
private:
    
    void appendLastElements(ListNode*& currentPtr, ListNode* node, bool carry) {
        
        while (node != nullptr) {
            int num = node->val + (int)carry;
            carry = false;
            if (num >= 10) {
                carry = true;
                num -= 10;
            }
            
            ListNode* tmpPtr = new ListNode;
            tmpPtr->val = num;
            tmpPtr->next = nullptr;
            currentPtr->next = tmpPtr;
            currentPtr = currentPtr->next;
            
            node = node->next;
        }
        
        if (carry == true) {
            ListNode* tmpPtr = new ListNode;
            tmpPtr->val = 1;
            tmpPtr->next = nullptr;
            currentPtr->next = tmpPtr;
            currentPtr = currentPtr->next;
        }
    }
};