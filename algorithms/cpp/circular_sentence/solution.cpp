class Solution {
public:
    bool isCircularSentence(const std::string& sentence) {
        std::optional<char> last;
        std::string out;
        std::istringstream iss(sentence);
        while (std::getline(iss, out, ' ')) {
            if (!last) {
                last = out.back();
                continue;
            }
            const auto first{ out.at(0) };
            if (first != last) {
                return false;
            }
            last = out.back();
        }
        return last == sentence.at(0);
    }
};
