namespace {

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

auto evaluateTree(auto node) {
    if (!node || !node->left || !node->right) {
        return;
    }
    evaluateTree(node->left);
    evaluateTree(node->right);
    const auto lhs{ node->left->val };
    const auto rhs{ node->right->val };
    if (lhs == 1 || lhs == 0 && rhs == 1 || rhs == 0) {
        bool eval{ node->val == 3 ? lhs && rhs : lhs || rhs };
        node->val = static_cast<int>(eval);
    }
}

}

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        ::evaluateTree(root);
        return static_cast<bool>(root->val);
    }
};