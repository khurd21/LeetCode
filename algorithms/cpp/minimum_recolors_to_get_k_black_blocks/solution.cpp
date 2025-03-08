class Solution {
public:
    int minimumRecolors(const std::string& blocks, int k) {

        std::uint8_t count{};
        auto left{ blocks.cbegin() };
        auto right{ blocks.cbegin() + k - 1 };
        for (auto iter{ left }; iter <= right; ++iter) {
            count += static_cast<int>(*iter == 'W');
        }
        auto result = count;

        while (right + 1 < blocks.cend()) {
            ++right;
            count += static_cast<int>(*right == 'W');
            count -= static_cast<int>(*left == 'W');
            result = std::min(result, count);
            ++left;
        }

        return result;
    }
};
