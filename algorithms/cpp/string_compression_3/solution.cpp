class Solution {
public:
    std::string compressedString(const std::string &word) {
        std::string comp;
        auto previous{ word.at(0) };
        int count{};

        const auto append = [&](auto num, const auto letter) {
            while (num > 0) {
                comp += std::format("{}{}", std::to_string(num > 9 ? 9 : num), letter);
                num -= 9;
            }
        };

        std::ranges::for_each(word, [&](const auto letter) {
            count += static_cast<int>(letter == previous);
            if (letter != previous) {
                append(count, previous);
                count = 1;
            }
            previous = letter;
        });
        
        append(count, previous);
        return comp;
    }
};
