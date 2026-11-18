// LeetCode 12: Integer to Roman
// https://leetcode.com/problems/integer-to-roman/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        const vector<pair<int, string>> values = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        string result;
        for (const auto& entry : values) {
            while (num >= entry.first) {
                result += entry.second;
                num -= entry.first;
            }
        }

        return result;
    }
};
