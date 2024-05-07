namespace {

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

}

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        auto result{ head };
        head->val *= 2;
        if (head->val > 9) {
            auto newNode = new ListNode(1, head);
            head->val = head->val % 10;
            result = newNode;
        }

        auto previous{ head };
        head = head->next;
        while (head) {
            const auto doubled{ head->val * 2 };
            previous->val += static_cast<int>(doubled / 10);
            head->val = doubled % 10;
            previous = head;
            head = head->next;
        }
        return result;
        
    }
};