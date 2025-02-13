class Solution {
public:
    int minOperations(const std::vector<int>& nums, int k) {
        std::multiset<std::uint64_t> ms{ nums.cbegin(), nums.cend() };
        int result{};
        while (ms.size() >= 2) {
            if (*ms.cbegin() >= k) {
                break;
            }

            auto itr{ ms.cbegin() };
            const auto first{ *itr };
            ms.erase(itr);
            itr = ms.cbegin();
            const auto second{ *itr };
            ms.erase(itr);

            ms.insert(std::min(first, second) * 2 + std::max(first, second));
            ++result;
        }
        return result;
    }
};
