/* **********************************************************************
 * Link: https://leetcode.com/problems/balanced-binary-tree/
 * Author: Kyle Hurd
 * **********************************************************************
 * Given a binary tree, determine if it is height-balanced.
 * 
 * Example 1:
 * 
 * Input: root = [3,9,20,null,null,15,7]
 * Output: true
 * 
 * Example 2:
 * 
 * Input: root = [1,2,2,3,3,null,null,4,4]
 * Output: false
 * 
 * Example 3:
 * 
 * Input: root = []
 * Output: true
 * 
 * Constraints:
 * 
 * The number of nodes in the tree is in the range [0, 5000].
 * -10^4 <= Node.val <= 10^4
 */

#include<algorithm>

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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        if (is_balanced(root) == -1) {
            return false;
        }

        return true;
    }

private:
    int is_balanced(TreeNode* node) {

        if (node == nullptr) {
            return 0;
        }

        int left{ is_balanced(node->left) };
        if (left == -1) {
            return left;
        }

        int right{ is_balanced(node->right) };
        if (right == -1) {
            return right;
        }

        if (std::abs(left - right) > 1) {
            return -1;
        }

        return std::max(left, right) + 1;
    }
};