#include <vector>

namespace {

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

auto len(auto node) {
    int length{};
    while (node) {
        ++length;
        node = node->next;
    }
    return length;
}

auto sliceNode(const auto node) {
    const auto nextNode{ node->next };
    node->next = nullptr;
    return nextNode;
}

auto update(auto& numPartsAdded, auto& index, auto& remainder) {
    numPartsAdded = 0;
    ++index;
    --remainder;
}

}

class Solution {
public:
    std::vector<ListNode*> splitListToParts(ListNode* head, int k) {
        const auto length{ len(head) };
        const auto nodesPerPart{ static_cast<int>(length / k) };
        std::vector<ListNode*> result(k);

        std::size_t index{};
        int numPartsAdded{};
        auto remainder{ length % k };
        while (head) {
            if (numPartsAdded == 0) {
                result.at(index) = head;
            }
            ++numPartsAdded;
            if (nodesPerPart == 0 && remainder > 0) {
                update(numPartsAdded, index, remainder);
                head = sliceNode(head);
                continue;
            }
            if (nodesPerPart == numPartsAdded) {
                head = (remainder > 0 && head->next) ? head->next : head;
                update(numPartsAdded, index, remainder);
                head = sliceNode(head);
                continue;
            }
            head = head->next;
        }

        return result;
    }
};
