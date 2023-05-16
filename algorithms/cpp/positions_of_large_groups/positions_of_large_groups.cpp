/*
In a string s of lowercase letters, these letters form consecutive groups of the
same character.

For example, a string like s = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z",
and "yy".

A group is identified by an interval [start, end], where start and end denote
the start and end indices (inclusive) of the group. In the above example,
"xxxx" has the interval [3,6].

A group is considered large if it has 3 or more characters.

Return the intervals of every large group sorted in increasing order by start index.

 

Example 1:

Input: s = "abbxxxxzzy"
Output: [[3,6]]
Explanation: "xxxx" is the only large group with start index 3 and end index 6.
Example 2:

Input: s = "abc"
Output: []
Explanation: We have groups "a", "b", and "c", none of which are large groups.
Example 3:

Input: s = "abcdddeeeeaabbbcd"
Output: [[3,5],[6,9],[12,14]]
Explanation: The large groups are "ddd", "eeee", and "bbb".
 

Constraints:

1 <= s.length <= 1000
s contains lowercase English letters only.
*/

#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<int>> largeGroupPositions(const std::string& s) {

        const int group_threshold{ 3 };

        std::vector<std::vector<int>> result;
        int start{ 0 };
        int counter{ 0 };
        auto current_value{ s[0] };

        std::for_each(s.begin(), s.end(), [&](const auto value) {

            if (value == current_value) {
                ++counter;
            }
            else {
                this->add_item(result, start, counter, group_threshold);
                start += counter;
                counter = 1;
                current_value = value;
            }
        });

        this->add_item(result, start, counter, group_threshold);

        return result;
    }

private:
    constexpr void add_item(
        std::vector<std::vector<int>>& container,
        const int beginning,
        const int num_items,
        const int threshold)
    {
        if (num_items >= threshold) {
            container.push_back( { beginning, beginning + num_items - 1 } );
        }
    }
};