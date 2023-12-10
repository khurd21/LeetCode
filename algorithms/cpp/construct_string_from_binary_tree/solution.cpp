#include <string>

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

class Solution {
public:
    std::string tree2str(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        std::string result;
        helper(root, result);
        return result;
    }

private:
    void helper(TreeNode* node, std::string& result) {
        if (node == nullptr) {
            return;
        }
        result += std::to_string(node->val);
        if (node->left != nullptr || node->right != nullptr) {
            result += "(";
            helper(node->left, result);
            result += ")";
        }
        if (node->right !=nullptr) {
            result += "(";
            helper(node->right, result);
            result += ")";
        }
    }
};