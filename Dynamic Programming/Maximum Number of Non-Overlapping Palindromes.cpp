#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // dp[i] = maximum number of valid non-overlapping palindromes
        // that can be selected from the prefix s[0...i-1].
        vector<int> dp(n + 1, 0);

        // We'll discover palindromes by expanding around every center.
        // This avoids storing the complete O(n^2) palindrome table.
        for (int center = 0; center < n; center++) {
            int l = center, r = center;
            while (l >= 0 && r < n && s[l] == s[r]) {
                int len = r - l + 1;
                if (len >= k) {
                    dp[r + 1] = max(dp[r + 1], dp[l] + 1);
                }
                --l;
                ++r;
            }
        }

        // Even when no palindrome ends at i-1, we can skip that character.
        for (int i = 1; i <= n; i++) {
            dp[i] = max(dp[i], dp[i - 1]);
        }

        return dp[n];
    }
};

// Alternative approach: expand around each center.
// Time Complexity: O(n^2) in the worst case.
// Space Complexity: O(n).
