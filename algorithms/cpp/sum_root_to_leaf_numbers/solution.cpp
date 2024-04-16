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

void sums(auto node, auto& number, auto& result) {
    if (!node) {
        return;
    }
    number.push_back(static_cast<char>(node->val + '0'));
    sums(node->left, number, result);
    sums(node->right, number, result);
    if (!node->left && !node->right) {
        result += std::stoi(number);
    }
    number.pop_back();
}

}

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int result{};
        std::string number;
        sums(root, number, result);
        return result;
    }
};