class Solution {
public:
    int findCenter(const std::vector<std::vector<int>>& edges) {
        auto edge1{ edges.at(0) };
        auto edge2{ edges.at(1) };
        std::sort(edge1.begin(), edge1.end());
        std::sort(edge2.begin(), edge2.end());
        if (edge1.at(0) == edge2.at(0)) {
            return edge1.at(0);
        }
        return edge1.at(1);
    }
};
