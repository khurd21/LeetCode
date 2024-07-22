#include <vector>
#include <algorithm>

namespace {

struct Person {
    std::string name;
    int height;
};

}

class Solution {
public:
    std::vector<std::string> sortPeople(const std::vector<std::string>& names, const std::vector<int>& heights) {
        std::vector<Person> people;
        for (std::size_t index{}; index < names.size() && index < heights.size(); ++index) {
            people.emplace_back(names.at(index), heights.at(index));
        }
        std::sort(people.begin(), people.end(), [](const auto& lhs, const auto& rhs) {
            return lhs.height > rhs.height;
        });
        std::vector<std::string> result(people.size());
        std::transform(people.cbegin(), people.cend(), result.begin(), [](const auto& person) {
            return person.name;
        });
        return result;
    }
};
