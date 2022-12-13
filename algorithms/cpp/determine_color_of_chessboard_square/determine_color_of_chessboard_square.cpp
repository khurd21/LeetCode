/* **********************************************************************
 * Link: https://leetcode.com/problems/determine-color-of-a-chessboard-square/
 * Author: Kyle Hurd
 * **********************************************************************
 * 
 * **********************************************************************
 * Description:
 * 
 * You are given coordinates, a string that represents the coordinates of
 * a square of the chessboard. Below is a chessboard for your reference.
 * 
 * Return true if the square is white, and false if the square is black.
 * 
 * The coordinate will always represent a valid chessboard square.
 * The coordinate will always have the letter first, and the number second.
 * **********************************************************************
 * 
 * **********************************************************************
 * Example 1:
 * 
 * Input: coordinates = "a1"
 * Output: false
 * Explanation: From the chessboard above, the square with coordinates "a1" is black, so return false.
 * 
 * Example 2:
 * 
 * Input: coordinates = "h3"
 * Output: true
 * Explanation: From the chessboard above, the square with coordinates "h3" is white, so return true.
 * 
 * Example 3:
 * 
 * Input: coordinates = "c7"
 * Output: false
 * **********************************************************************
 * 
 * ********************************************************************** 
 * Constraints:
 * 
 * coordinates.length == 2
 * 'a' <= coordinates[0] <= 'h'
 * '1' <= coordinates[1] <= '8'
 */

#include <string>

class Solution {
public:
    bool squareIsWhite(const std::string coordinates) {

        const char letter = coordinates[0];
        const char number = coordinates[1];

        const bool is_letter_odd = letter % 2 == 1;
        const bool is_number_odd = number % 2 == 1;

        if (is_letter_odd & is_number_odd ||
            !is_letter_odd & !is_number_odd) {
            return false;
        }
        return true;
    }
};