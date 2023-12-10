#include <vector>

namespace {

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorderTraversalHelper(TreeNode* node, std::vector<int>& values) {
    if (node == nullptr) {
        return;
    }
    inorderTraversalHelper(node->left, values);
    values.push_back(node->val);
    inorderTraversalHelper(node->right, values);
}

}

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) const {
        std::vector<int> result;
        inorderTraversalHelper(root, result);
        return result;
    }
};