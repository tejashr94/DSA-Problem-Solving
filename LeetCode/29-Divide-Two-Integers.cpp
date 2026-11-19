// LeetCode 29: Divide Two Integers
// https://leetcode.com/problems/divide-two-integers/

#include <climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        long long a = dividend;
        long long b = divisor;
        bool negative = (a < 0) != (b < 0);
        a = a < 0 ? -a : a;
        b = b < 0 ? -b : b;

        long long result = 0;
        for (int bit = 31; bit >= 0; --bit) {
            if ((a >> bit) >= b) {
                a -= b << bit;
                result += 1LL << bit;
            }
        }
        return negative ? -(int)result : (int)result;
    }
};