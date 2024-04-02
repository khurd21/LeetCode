#include <string>
#include <unordered_map>

namespace {

template <typename Iter>
auto canMap(Iter first_s, Iter last_s, Iter first_t, Iter last_t) {
    using ValueType = typename std::iterator_traits<Iter>::value_type;
    std::unordered_map<ValueType, ValueType> m;
    while (first_s < last_s && first_t < last_t) {
        const auto key{ *first_s };
        const auto value{ *first_t };
        if (m.contains(key) && m.at(key) != value) {
            return false;
        }
        m.emplace(key, value);
        ++first_s;
        ++first_t;
    }
    return true;
}

template <typename Iter>
auto isIsomorphic(Iter first_s, Iter last_s, Iter first_t, Iter last_t) {
    return canMap(first_s, last_s, first_t, last_t) && canMap(first_t, last_t, first_s, last_s);
}

}

class Solution {
public:
    bool isIsomorphic(const std::string& s, const std::string& t) {
        if (s.size() != t.size()) {
            return {};
        }

        return ::isIsomorphic(s.cbegin(), s.cend(), t.cbegin(), t.cend());
    }
};