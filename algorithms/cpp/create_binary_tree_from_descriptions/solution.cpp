#include <unordered_map>
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

}

class Solution {
public:
    TreeNode* createBinaryTree(std::vector<std::vector<int>>& descriptions) {
        std::unordered_map<int, TreeNode*> nodes;
        for (const auto& description : descriptions) {
            const auto& parent{ description.at(0) };
            const auto& child{ description.at(1) };
            const auto& isLeft{ static_cast<bool>(description.at(2) == 1) };

            if (!nodes.contains(parent)) {
                nodes.insert({parent, new TreeNode(parent)});
            }
            if (!nodes.contains(child)) {
                nodes.insert({child, new TreeNode(child)});
            }

            auto& leaf{ isLeft ? nodes.at(parent)->left : nodes.at(parent)->right };
            leaf = nodes.at(child);
        }

        for (const auto& description : descriptions) {
            const auto& child{ description.at(1) };
            if (nodes.contains(child)) {
                nodes.erase(child);
            }
        }
        return nodes.begin()->second;
    }
};
