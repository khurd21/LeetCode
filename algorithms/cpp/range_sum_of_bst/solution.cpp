namespace {

struct TreeNode {
    int val;
     TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

} // namespace

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        m_low = low;
        m_high = high;
        int result{};
        helper(root, result);
        return result;
    }

private:
    void helper(TreeNode* node, int& sum) {
        if (node == nullptr) {
            return;
        }

        if (node->val >= m_low && node->val <= m_high) {
            sum += node->val;
        }

        if (node->val >= m_low) {
            helper(node->left, sum);
        }
        
        if (node->val <= m_high) {
            helper(node->right, sum);
        }
    }

    int m_low{};
    int m_high{};
};