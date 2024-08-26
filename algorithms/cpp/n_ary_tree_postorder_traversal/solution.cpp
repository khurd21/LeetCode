#include <vector>

namespace {

class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

auto postorder(auto node, auto& container) {
    if (!node) {
        return;
    }
    for (const auto child : node->children) {
        postorder(child, container);
    }
    container.emplace_back(node->val);
}

}

class Solution {
public:
    std::vector<int> postorder(Node* root) {
        std::vector<int> result;
        ::postorder(root, result);
        return result;
    }
};