#include <unordered_map>

namespace {

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

auto canBePalindrome(const auto& count) {
    bool isOddFound{};
    for (const auto& [key, value] : count) {
        if (value % 2 == 1) {
            if (isOddFound) {
                return false;
            }
            isOddFound = true;
        }
    }
    return true;
}

auto helper(TreeNode* node, auto& result, auto& count) {
    if (!node) {
        return;
    }

    count[node->val] += 1;
    helper(node->left, result, count);
    helper(node->right, result, count);

    if (!node->left && !node->right) {
        result += static_cast<int>(canBePalindrome(count));
    }
    count[node->val] -= 1;
}

auto producePaths(TreeNode* node) {
    int result{};
    std::unordered_map<int, int> count;
    helper(node, result, count);
    return result;
}

} // namespace

class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        return producePaths(root);
    }
};