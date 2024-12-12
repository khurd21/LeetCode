class Solution {
public:
    long long pickGifts(const std::vector<int>& gifts, int k) {
        std::priority_queue<int> q(gifts.cbegin(), gifts.cend());
        while (!q.empty() && k-- > 0) {
            const auto top{ q.top() };
            const auto remaining{ static_cast<int>(std::floor(std::sqrt(top))) };
            q.pop();
            q.push(remaining);
        }

        long long result{};
        while (!q.empty()) {
            result += q.top();
            q.pop();
        }
        return result;
    }
};
