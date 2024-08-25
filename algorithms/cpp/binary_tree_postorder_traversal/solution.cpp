#include <vector>

namespace {

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

auto postorderTraversal(auto node, auto& container) {
    if (!node) {
        return;
    }
    postorderTraversal(node->left, container);
    postorderTraversal(node->right, container);
    container.emplace_back(node->val);
}

}

class Solution {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;
        ::postorderTraversal(root, result);
        return result;
    }
};
