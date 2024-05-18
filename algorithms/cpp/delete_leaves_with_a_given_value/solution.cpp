namespace {

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

auto removeLeafNodes(auto& node, const auto target) {
    if (!node) {
        return;
    }
    removeLeafNodes(node->left, target);
    removeLeafNodes(node->right, target);
    if (!node->left && !node->right && node->val == target) {
        // delete node; Y U Crash?
        node = nullptr;
    }
}

}

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        ::removeLeafNodes(root, target);
        return root;
    }
};