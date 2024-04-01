#include <type_traits>
#include <iterator>
#include <vector>

namespace {

template <typename Iter, typename T,
typename = std::enable_if<std::is_same_v<typename std::iterator_traits<Iter>::value_type, T>>>
auto countSubarrays(Iter begin, Iter end, T minK, T maxK) {
    long long result{};
    auto badItr{ begin - 1 };
    auto minItr{ begin - 1 };
    auto maxItr{ begin - 1 };

    while (begin < end) {
        if (*begin > maxK || *begin < minK) {
            badItr = begin;
        }
        if (*begin == minK) {
            minItr = begin;
        }
        if (*begin == maxK) {
            maxItr = begin;
        }

        const auto start{ std::min(maxItr, minItr) };
        if (start > badItr) {
            result += std::abs(std::distance(start, badItr));
        }
        ++begin;
    }

    return result;
}

}


class Solution {
public:
    long long countSubarrays(const std::vector<int>& nums, int minK, int maxK) {
        return ::countSubarrays(nums.cbegin(), nums.cend(), minK, maxK);
    }
};