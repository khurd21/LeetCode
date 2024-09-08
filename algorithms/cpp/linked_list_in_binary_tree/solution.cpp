namespace {

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

auto check(const auto nodeLinkedList, const auto nodeTree, auto& isPath) {
    if (!nodeLinkedList) {
        isPath = true;
    }
    if (!nodeTree) {
        return true;
    }
    return isPath;
}

auto isSubPathHelper(const auto nodeLinkedList, const auto nodeTree, auto& isPath) {
    if (check(nodeLinkedList, nodeTree, isPath)) {
        return;
    }

    if (nodeTree->val == nodeLinkedList->val) {
        isSubPathHelper(nodeLinkedList->next, nodeTree->left, isPath);
        isSubPathHelper(nodeLinkedList->next, nodeTree->right, isPath);
    }
}

auto isSubPath(const auto nodeLinkedList, const auto nodeTree, auto& isPath) {
    if (check(nodeLinkedList, nodeTree, isPath)) {
        return;
    }

    if (nodeTree->val == nodeLinkedList->val) {
        isSubPathHelper(nodeLinkedList, nodeTree, isPath);
    }

    isSubPath(nodeLinkedList, nodeTree->left, isPath);
    isSubPath(nodeLinkedList, nodeTree->right, isPath);
}

}

class Solution {
public:
    bool isSubPath(const ListNode* head, const TreeNode* root) {
        bool isPath{};
        ::isSubPath(head, root, isPath);
        return isPath;
    }
};
