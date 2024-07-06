#include <vector>
#include <optional>

namespace {

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

namespace {

auto minDistance(auto node) {

    if (!node) {
        return -1;
    }

    auto previousNode{ node };
    std::optional<int> firstIndex;
    std::optional<int> result;
    
    int index{ 1 };
    node = node->next;
    while (node && node->next) {
        if (previousNode->val < node->val && node->next->val < node->val ||
                previousNode->val > node->val && node->next->val > node->val) {
            if (!firstIndex.has_value()) {
                firstIndex = index;
            }
            else {
                result = std::min(result.value_or(std::numeric_limits<int>::max()), index - firstIndex.value());
            }
            firstIndex = index;
        }
        ++index;
        previousNode = node;
        node = node->next;
    }

    return result.value_or(-1);
}

auto maxDistance(auto node) {
    if (!node) {
        return -1;
    }

    auto previousNode{ node };
    std::optional<int> firstIndex;
    std::optional<int> lastIndex;
    std::optional<int> result;

    int index{ 1 };
    node = node->next;
    while (node && node->next) {
        if (previousNode->val < node->val && node->next->val < node->val ||
                previousNode->val > node->val && node->next->val > node->val) {
            if (!firstIndex.has_value()) {
                firstIndex = index;
            }
            else {
                lastIndex = index;
                result = lastIndex.value() - firstIndex.value();
            }
        }
        ++index;
        previousNode = node;
        node = node->next;
    }

    return result.has_value() ? result.value() : -1;
}

}

class Solution {
public:
    std::vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        return { minDistance(head), maxDistance(head) };
    }
};
