class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> result(temperatures.size());
        std::stack<std::pair<int, int>> stack;
        for (int i{}; i < temperatures.size(); ++i) {
            const auto temperature{ temperatures.at(i) };
            while (!stack.empty() && temperature > stack.top().first) {
                const auto value{ stack.top() };
                stack.pop();
                result.at(value.second) = i - value.second;
            }
            stack.push({temperature, i});
        }
        return result;
    }
};
