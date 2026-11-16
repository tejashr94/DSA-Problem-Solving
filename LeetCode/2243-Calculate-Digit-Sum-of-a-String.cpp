// LeetCode 2243. Calculate Digit Sum of a String
// https://leetcode.com/problems/calculate-digit-sum-of-a-string/
//
// Repeatedly partition the string into consecutive groups of size k,
// sum the digits in each group, and concatenate the sums until the
// resulting string has at most k characters.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string next;

            for (int i = 0; i < (int)s.size(); i += k) {
                int sum = 0;

                for (int j = i; j < min(i + k, (int)s.size()); ++j) {
                    sum += s[j] - '0';
                }

                next += to_string(sum);
            }

            s = next;
        }

        return s;
    }
};

// Time Complexity: O(n log_k n) across repeated grouping rounds.
// Space Complexity: O(n) for the newly generated string.
