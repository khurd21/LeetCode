#include <unordered_set>
#include <algorithm>
#include <vector>

class Solution {
public:
    template <typename Container>
    auto containsDuplicate(Container&& container) {
        using Type = typename std::decay_t<Container>::value_type;
        std::unordered_set<Type> s;
        for (const auto& value : container) {
            if (s.contains(value)) {
                return true;
            }
            s.insert(value);
        }
        return false;
    }
};

class Solution {
public:
    bool containsDuplicate(std::vector<int> nums) {
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }
};