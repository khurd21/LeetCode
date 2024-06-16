#include <string>
#include <vector>

namespace {

auto parse(const auto& s, auto& numbers, auto& expressions) {
    for (auto itr{ s.cbegin() }; itr < s.cend(); ++itr) {
        if (std::isdigit(*itr)) {
            const auto tmp{ itr };
            while (itr < s.cend() && std::isdigit(*itr)) {
                ++itr;
            }
            numbers.push_back(std::stoi(std::string(tmp, itr)));
            --itr;
        }
        else if (*itr != ' ') {
            expressions.push_back(*itr);
        }
    }
}

auto handle_md(auto& numbers, auto& expressions) {
    for (std::size_t i{}; i < expressions.size(); ++i) {
        const auto& expression{ expressions.at(i) };
        if (expression == '*') {
            numbers.at(i + 1) = numbers.at(i) * numbers.at(i + 1);
            numbers.at(i) = -1;
        }
        if (expression == '/') {
            numbers.at(i + 1) = numbers.at(i) / numbers.at(i + 1);
            numbers.at(i) = -1;
        }
    }
}

auto handle_as(auto& numbers, auto& expressions) {
    for (std::size_t i{}; i < expressions.size(); ++i) {
        const auto& expression{ expressions.at(i) };
        if (expression == '+') {
            numbers.at(i + 1) = numbers.at(i) + numbers.at(i + 1);
            numbers.at(i) = -1;
        }
        if (expression == '-') {
            numbers.at(i + 1) = numbers.at(i) - numbers.at(i + 1);
            numbers.at(i) = -1;
        }
    }
}

}

class Solution {
public:
    int calculate(const std::string& s) {
        std::vector<int> numbers;
        std::vector<char> expressions;

        parse(s, numbers, expressions);
        handle_md(numbers, expressions);
        numbers.erase(std::remove(numbers.begin(), numbers.end(), -1), numbers.end());
        expressions.erase(std::remove_if(expressions.begin(), expressions.end(), [](const auto& c) {
            return c == '*' || c == '/';
        }), expressions.end());
        handle_as(numbers, expressions);
        return numbers.back();
    }
};