struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        auto slow = head;
        auto fast = head;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
            if (fast) {
                fast = fast->next;
            }
            if (slow == fast && fast != nullptr) {
                return true;
            }
        }

        return false;
    }
};