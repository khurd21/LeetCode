namespace {

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

auto distributeCoins(auto node, auto& moves) {
    if (!node) {
        return 0;
    }
    const auto lhs{ distributeCoins(node->left, moves) };
    const auto rhs{ distributeCoins(node->right, moves) };
    moves += std::abs(lhs) + std::abs(rhs);
    return node->val + lhs + rhs - 1;
}

}

class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int moves{};
        ::distributeCoins(root, moves);
        return moves;
    }
};