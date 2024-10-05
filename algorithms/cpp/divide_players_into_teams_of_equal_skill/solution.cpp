class Solution {
public:
    long long dividePlayers(std::vector<int> skill) {
        const auto min{ std::ranges::min(std::as_const(skill)) };
        const auto max{ std::ranges::max(std::as_const(skill)) };
        const auto target_sum{ min + max };

        std::unordered_map<int, int> m;
        std::ranges::for_each(std::as_const(skill), [&](const auto level) {
            m[level] += 1;
        });

        long long result{};
        auto itr{ m.begin() };
        while (itr != m.end()) {
            const auto level{ itr->first };
            const auto complement{ target_sum - level };
            if (m.contains(complement)) {
                
            }
        }
    }
};
