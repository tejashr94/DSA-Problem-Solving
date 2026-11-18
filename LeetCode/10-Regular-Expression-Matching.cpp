// LeetCode 10: Regular Expression Matching
// https://leetcode.com/problems/regular-expression-matching/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = static_cast<int>(s.size());
        int n = static_cast<int>(p.size());
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;

        // Empty string can match patterns such as a*, a*b*, etc.
        for (int j = 2; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*' && j >= 2) {
                    // Treat x* as zero occurrences of x.
                    dp[i][j] = dp[i][j - 2];

                    // Or consume one matching character and keep x*.
                    char preceding = p[j - 2];
                    if (preceding == '.' || preceding == s[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }

        return dp[m][n];
    }
};
