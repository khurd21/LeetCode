#include <type_traits>
#include <vector>

namespace {

template <typename Iter, typename K>
typename std::enable_if_t<std::is_arithmetic_v<K>, K>
subarraysWithKDistinct(Iter begin, Iter end, K k) {
    using KeyType = std::iterator_traits<Iter>::value_type;
    std::unordered_map<KeyType, K> m;
    auto left{ begin };
    auto right{ begin };
    K result{};
    while (begin < end) {
        m[*begin] += 1;
        while (static_cast<K>(m.size()) > k) {
            m.at(*right) -= 1;
            if (m.at(*right) == 0) {
                m.erase(*right);
            }
            ++right;
            left = right;
        }
        while (m.at(*right) > 1) {
            m.at(*right) -= 1;
            ++right;
        }

        if (static_cast<K>(m.size()) == k) {
            result += static_cast<K>(right - left) + 1;
        }
        ++begin;
    }
    return result;
}

}

class Solution {
public:
    int subarraysWithKDistinct(std::vector<int>& nums, int k) {
        return ::subarraysWithKDistinct(nums.cbegin(), nums.cend(), k);
    }
};