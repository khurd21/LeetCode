namespace {

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

auto getLength(ListNode* node) {
    int len{};
    while (node) {
        ++len;
        node = node->next;
    }
    return len;
}

} // namespace

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        const auto length{ getLength(head) };
        for (int i{}; i < length / 2; ++i) {
            head = head->next;
        }
        return head;
    }
};