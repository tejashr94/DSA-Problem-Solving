#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // dp[i] = maximum number of non-overlapping palindromes
        // that can be selected from the first i characters.
        vector<int> dp(n + 1, 0);

        // Process palindrome endings from left to right so dp[l]
        // is already finalized when a palindrome [l...r] is used.
        for (int r = 0; r < n; r++) {
            dp[r + 1] = dp[r]; // Skip s[r].

            // Expand every possible palindrome ending at r.
            for (int l = r; l >= 0; l--) {
                if (s[l] != s[r]) continue;

                bool palindrome = (r - l < 2);
                if (!palindrome) {
                    // Check inward characters directly.
                    palindrome = true;
                    int a = l + 1, b = r - 1;
                    while (a < b) {
                        if (s[a++] != s[b--]) {
                            palindrome = false;
                            break;
                        }
                    }
                }

                if (palindrome && r - l + 1 >= k) {
                    dp[r + 1] = max(dp[r + 1], dp[l] + 1);
                }
            }
        }

        return dp[n];
    }
};

// Alternative DP approach: process each ending position and search for
// palindromic substrings ending there.
// Time Complexity: O(n^3) worst case due to direct palindrome checking.
// Space Complexity: O(n).
