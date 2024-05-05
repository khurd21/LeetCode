namespace {

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

}

class Solution {
public:
    void deleteNode(ListNode* node) {
        // This is messed up.
        node->val = node->next->val;
        node->next = node->next->next;
    }
};