class Solution {
public:
    int maxChunksToSorted(const std::vector<int>& arr) {
        auto max{ std::numeric_limits<int>::min() };
        int result{};
        for (std::size_t index{}; index < arr.size(); ++index) {
            max = std::max(arr.at(index), max);
            result += static_cast<int>(max == index);
        }
        return result;
    }
};
