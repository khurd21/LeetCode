#include <vector>

namespace {

template <typename Iter, typename Target>
auto timeRequired(Iter begin, Iter end, const Target& target) {
    Target result{};
    while (begin < end) {
        result += std::min(*begin, target);
        ++begin;
    }
    return result;
}

}

class Solution {
public:
    int timeRequiredToBuy(const std::vector<int>& tickets, const int k) {
        if (k > tickets.size() || k < 0) {
            return {};
        }

        const auto& quantity{ tickets.at(k) };
        return timeRequired(tickets.cbegin(), tickets.cbegin() + k + 1, quantity) +
                timeRequired(tickets.cbegin() + k + 1, tickets.cend(), quantity - 1);
    }
};