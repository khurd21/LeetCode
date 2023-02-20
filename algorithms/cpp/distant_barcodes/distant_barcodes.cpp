/*
 * In a warehouse, there is a row of barcodes, where the ith barcode
 * is barcodes[i].
 * 
 * Rearrange the barcodes so that no two adjacent barcodes are equal. You may
 * return any answer, and it is guaranteed an answer exists.
 * 
 * Example 1:
 * 
 * Input: barcodes = [1,1,1,2,2,2]
 * Output: [2,1,2,1,2,1]
 * 
 * Example 2:
 * 
 * Input: barcodes = [1,1,1,1,2,2,3,3]
 * Output: [1,3,1,3,1,2,1,2]
 * 
 * Constraints:
 * 
 * 1 <= barcodes.length <= 10000
 * 1 <= barcodes[i] <= 10000
 */

#include <vector>
#include <map>
#include <unordered_map>

class Solution {
public:
    std::vector<int> rearrangeBarcodes(const std::vector<int>& barcodes) {

        // key: barcode, value: size()
        std::unordered_map<int, int> m;

        // key: size(), value: [ barcodes with that size, ... ]
        std::map<int, std::vector<int>, std::greater<int>> barcode_map;
        std::vector<int> result(barcodes.size());

        for (const auto& barcode : barcodes) {
            if (m.find(barcode) == m.end()) {
                m.insert({barcode, 1});
            }
            else {
                m[barcode] += 1;
            }
        }

        for (const auto& [barcode, amount] : m) {
            if (barcode_map.find(amount) == barcode_map.end()) {
                barcode_map.insert({amount, { barcode }});
            }
            else {
                barcode_map[amount].push_back(barcode);
            }
        }

        int itr{ 0 };
        for (const auto& [amount, barcodes] : barcode_map) {
            for (const auto barcode : barcodes) {
                for (int tmp{ 0 }; tmp < amount; ++tmp) {
                    result[itr] = barcode;
                    itr += 2;
                    if (itr >= result.size()) {
                        itr = 1;
                    }
                }
            }
        }

        return result;
    }
};