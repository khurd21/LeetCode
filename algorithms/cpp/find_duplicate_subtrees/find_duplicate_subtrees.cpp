/*
Given the root of a binary tree, return all duplicate subtrees.

For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with the same node values.

 

Example 1:


Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]
Example 2:


Input: root = [2,1,1]
Output: [[1]]
Example 3:


Input: root = [2,2,2,3,null,3,null]
Output: [[2,3],[3]]
 

Constraints:

The number of the nodes in the tree will be in the range [1, 5000]
-200 <= Node.val <= 200
*/

#include <vector>
#include <unordered_map>
#include <string>

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
    std::vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        std::vector<TreeNode*> duplicates;
        std::unordered_map<std::string, int> map;
        find_duplicates(root, duplicates, map);
        return duplicates;
    }

private:
    const std::string null_node{ "N/A" };

    std::string find_duplicates(TreeNode* node, std::vector<TreeNode*>& duplicates, std::unordered_map<std::string, int>& map) {
        
        if (node == nullptr) {
            return this->null_node;
        }

        std::string serialized_string{
            std::to_string(node->val) + "," +
            this->find_duplicates(node->left, duplicates, map) + "," +
            this->find_duplicates(node->right, duplicates, map)
        };

        if (map[serialized_string] == 1) {
            duplicates.push_back(node);
        }
        
        map[serialized_string] += 1;
        return serialized_string;
    }
};