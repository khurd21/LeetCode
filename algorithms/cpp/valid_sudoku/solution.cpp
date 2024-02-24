#include <vector>
#include <unordered_set>
#include <cctype>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        return isHorizontalValid(board) && isVerticalValid(board) && isSquareValid(board);
    }

private:
    bool isHorizontalValid(std::vector<std::vector<char>>& board) {

        for (const auto& row : board) {
            std::unordered_set<char> chars;
            for (const auto c : row) {
                if (!std::isdigit(c)) {
                    continue;
                }
                if (chars.contains(c)) {
                    return false;
                }
                chars.insert(c);
            }
        }

        return true;
    }

    bool isVerticalValid(std::vector<std::vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            std::unordered_set<char> chars;
            for (int j = 0; j < board[i].size(); ++j) {
                if (!std::isdigit(board[j][i])) {
                    continue;
                }
                if (chars.contains(board[j][i])) {
                    return false;
                }
                chars.insert(board[j][i]);
            }
        }
        return true;
    }

    bool isSquareValid(std::vector<std::vector<char>>& board) {
        auto check = [](const auto& board, int x, int y) -> bool {
            std::unordered_set<char> chars;
            for (int i = x; i < x + 3; ++i) {
                for (int j = y; j < y + 3; ++j) {
                    if (!std::isdigit(board[i][j])) {
                        continue;
                    }
                    if (chars.contains(board[i][j])) {
                        return false;
                    }
                    chars.insert(board[i][j]);
                }
            }
            return true;
        };

        for (int i = 0; i < board.size(); i += 3) {
            std::unordered_set<char> chars;
            for (int j = 0; j < board[i].size(); j += 3) {
                if (!check(board, i, j)) {
                    return false;
                }
            }
        }
        return true;
    }
};