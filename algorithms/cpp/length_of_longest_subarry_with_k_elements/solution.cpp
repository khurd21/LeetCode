#include <utility>
#include <vector>

namespace {

template <typename Iter, typename KeyType = typename std::decay<decltype(*std::declval<Iter>())>::type>
std::size_t maxLength(Iter begin, Iter end, const std::size_t k) {
    std::size_t result{};
    Iter left{ begin };
    Iter right{ begin };
    std::unordered_map<KeyType, int> m;
    while (begin < end) {
        m[*begin++] = 0;
    }

    while (right < end) {
        m.at(*right) += 1;
        while (m.at(*right) > k && left < right) {
            m.at(*left) -= 1;
            ++left;
        }
        result = std::max(result, static_cast<std::size_t>(right - left + 1));
        ++right;
    }
    
    return result;
}

}

class Solution {
public:
    int maxSubarrayLength(const std::vector<int>& nums, const int k) {
        return static_cast<int>(maxLength(nums.cbegin(), nums.cend(), k));
    }
};