// LeetCode 3: Longest Substring Without Repeating Characters
// Approach: Sliding window with last-seen indices
// Time: O(n), Space: O(min(n, character set))

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(256, -1);
        int left = 0, best = 0;

        for (int right = 0; right < (int)s.size(); ++right) {
            unsigned char ch = static_cast<unsigned char>(s[right]);
            left = max(left, lastSeen[ch] + 1);
            lastSeen[ch] = right;
            best = max(best, right - left + 1);
        }
        return best;
    }
};
