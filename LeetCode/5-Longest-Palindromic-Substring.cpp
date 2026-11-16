// LeetCode 5: Longest Palindromic Substring
// Approach: Expand around every possible center
// Time: O(n^2), Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
    pair<int, int> expand(const string& s, int left, int right) {
        while (left >= 0 && right < (int)s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return {left + 1, right - left - 1};
    }

public:
    string longestPalindrome(string s) {
        int start = 0, bestLength = 0;

        for (int i = 0; i < (int)s.size(); ++i) {
            auto odd = expand(s, i, i);
            auto even = expand(s, i, i + 1);

            if (odd.second > bestLength) {
                start = odd.first;
                bestLength = odd.second;
            }
            if (even.second > bestLength) {
                start = even.first;
                bestLength = even.second;
            }
        }
        return s.substr(start, bestLength);
    }
};
