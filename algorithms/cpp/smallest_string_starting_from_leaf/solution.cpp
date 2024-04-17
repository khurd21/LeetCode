#include <string>

namespace {

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void smallestFromLeaf(auto node, auto s, auto& result) {
    if (!node) {
        return;
    }

    s.insert(0, 1, static_cast<char>(node->val) + 'a');
    if (!node->left && !node->right) {
        result = std::min(result, s);
    }
    smallestFromLeaf(node->left, s, result);
    smallestFromLeaf(node->right, s, result);
}

}

class Solution {
public:
    std::string smallestFromLeaf(TreeNode* root) {
        std::string result(25, 'z');
        ::smallestFromLeaf(root, std::string(), result);
        return result;
    }
};