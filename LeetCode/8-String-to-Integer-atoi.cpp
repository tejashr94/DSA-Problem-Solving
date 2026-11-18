// LeetCode 8: String to Integer (atoi)
// https://leetcode.com/problems/string-to-integer-atoi/

#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = static_cast<int>(s.size());

        while (i < n && s[i] == ' ') {
            ++i;
        }

        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            ++i;
        }

        long long value = 0;
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            value = value * 10 + (s[i] - '0');

            if (sign == 1 && value > INT_MAX) {
                return INT_MAX;
            }
            if (sign == -1 && -value < INT_MIN) {
                return INT_MIN;
            }
            ++i;
        }

        return static_cast<int>(sign * value);
    }
};
