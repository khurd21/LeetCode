/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

 

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
 

Constraints:

1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
*/

#include <string>
#include <vector>

// FIRST ATTEMPT
class Solution {
public:
    std::string multiply(const std::string& num1, const std::string& num2) {
        
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        const auto sums{ this->get_sums(num1, num2) };
        return sum_strings(sums);
    }

private:
    std::vector<std::string> get_sums(const std::string& num1, const std::string& num2) {

        std::vector<std::string> sums;
        int zero_buffers{ 0 };

        std::for_each(num1.crbegin(), num1.crend(), [&](const char char1) {

            std::string tmp(zero_buffers, '0');
            int carry{};
            ++zero_buffers;

            std::for_each(num2.crbegin(), num2.crend(), [&](const char char2) {

                const int value{ (char1 - '0') * (char2 - '0') + carry };
                carry = value / 10;
                tmp = std::to_string(value % 10) + tmp;
            });

            if (carry != 0) {
                tmp = std::to_string(carry) + tmp;
            }

            sums.push_back(tmp);           
        });

        return sums;
    }

    std::string sum_strings(const std::vector<std::string>& numbers) {
        std::string sum{ "0" };
        for (const auto& number : numbers) {
            sum = this->add_strings(sum, number);
        }
        return sum;
    }

    std::string add_strings(const std::string& num1, const std::string& num2) {
        std::string r = "";
        const int sz1 = static_cast<int>(num1.size());
        const int sz2 = static_cast<int>(num2.size());
        int i = 0, j = 0, c = 0;
        while (i < sz1 || j < sz2 || c > 0) {
            int t = c;
            t += i < sz1 ? num1[sz1 - i - 1] - 48 : 0;
            t += j < sz2 ? num2[sz2 - j - 1] - 48 : 0;
            r = std::string(1, t % 10 + 48) + r;
            c = t / 10; // carry over next digit
            ++i;
            ++j;
        }
        return r;
    }
};

// SECOND ATTEMPT
class Solution {
public:
    std::string multiply(const std::string& num1, const std::string& num2) {

        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        std::string result;
        std::vector<int> sums(num1.length() + num2.length(), 0);

        for (int i = num1.length() - 1; i >= 0; --i) {
            for (int j = num2.length() - 1; j >= 0; --j) {
                sums[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                sums[i + j] += sums[i + j + 1] / 10;
                sums[i + j + 1] %= 10;
            }
        }

        auto ptr{ sums.cbegin() };
        while (*ptr == 0) { ++ptr; }
        while (ptr != sums.cend()) {
            result += std::to_string(*ptr);
            ++ptr;
        }

        return result;
    }
};