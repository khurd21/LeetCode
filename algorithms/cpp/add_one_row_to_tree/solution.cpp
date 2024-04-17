namespace {

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void addOneRow(auto node, const auto value, const auto depth, const auto currentDepth) {
    if (!node) {
        return;
    }
    if (currentDepth == depth - 1) {
        const auto leftNode{ new TreeNode(value, node->left, nullptr) };
        const auto rightNode{ new TreeNode(value, nullptr, node->right) };
        node->left = leftNode;
        node->right = rightNode;
        return;
    }
    addOneRow(node->left, value, depth, currentDepth + 1);
    addOneRow(node->right, value, depth, currentDepth + 1);
}

}
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            const auto newNode{ new TreeNode(val, root, nullptr) };
            return newNode;
        }
        ::addOneRow(root, val, depth, 1);
        return root;
    }
};