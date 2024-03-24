namespace {

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

auto reverse(auto node) {
    if (!node) {
        return node;
    }
    decltype(node) prev{ nullptr };
    decltype(node) next{ nullptr };
    auto current{ node };

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

auto merge(auto node1, auto node2) {

    while (node2) {
        auto next{ node1->next };
        node1->next = node2;
        node1 = node2;
        node2 = next;
    }
}

auto splitInHalf(auto head) {
    auto slow{ head };
    auto fast{ head };
    auto prev{ head };
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = nullptr;
    return slow;
}

}

class Solution {
public:
    void reorderList(ListNode* head) {

        if (!head || !head->next) {
            return;
        }

        auto mid{ splitInHalf(head) };
        auto node{ reverse(mid) };
        merge(head, node);
    }
};