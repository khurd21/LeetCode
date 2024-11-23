class Solution {
public:
    std::vector<std::vector<char>> rotateTheBox(std::vector<std::vector<char>> box) {
        shift(box);
        return transpose90(box);
    }

private:
    void shift(auto& container) {
        for (std::size_t index{}; index < container.size(); ++index) {
            auto& row{ container.at(index) };
            auto back{ row.size() - 1 };
            for (std::size_t jndex{ back }; jndex < std::numeric_limits<std::size_t>::max(); --jndex) {
                if (row.at(jndex) == obstacle) {
                    back = jndex - 1;
                    continue;
                }
                if (row.at(jndex) == stone) {
                    std::swap(row.at(back), row.at(jndex));
                    --back;
                }
            }
        }
    }

    std::vector<std::vector<char>> transpose90(const auto& container) {
        std::vector<std::vector<char>> result;
        for (std::size_t i{}; i < container.at(0).size(); ++i) {
            result.emplace_back(std::vector<char>(container.size()));
        }

        for (std::size_t index{}; index < container.size(); ++index) {
            for (std::size_t jndex{}; jndex < container.at(index).size(); ++jndex) {
                result.at(jndex).at(index) = container.at(index).at(jndex);
            }
        }

        for (std::size_t index{}; index < result.size(); ++index) {
            std::size_t begin{};
            std::size_t end{ result.at(index).size() - 1 };
            while (begin < end) {
                std::swap(result.at(index).at(begin), result.at(index).at(end));
                ++begin;
                --end;
            }
        }

        return result;
    }

    static constexpr auto stone{ '#' };
    static constexpr auto obstacle{ '*' };
    static constexpr auto empty{ '.' };
};
