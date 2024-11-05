class Solution {
public:
    int minChanges(const std::string& s) {
        int result{};
        for (std::size_t index{}; index < s.size() - 1; index += 2) {
            result += static_cast<int>(s.at(index) != s.at(index + 1));
        }
        return result;
    }
};
