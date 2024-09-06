#include <vector>
#include <unordered_set>

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
    ListNode* modifiedList(const std::vector<int>& nums, ListNode* head) {
        std::unordered_set<int> s(nums.cbegin(), nums.cend());
        auto node{ head };
        decltype(head) prev{ nullptr };

        while (node) {
            if (!s.contains(node->val)) {
                prev = node;
                node = node->next;
                continue;
            }

            if (prev) {
                prev->next = node->next;
                delete node;
                node = prev->next;
            }
            else {
                head = node->next;
                delete node;
                node = head;
            }
        }

        return head;
    }
};
