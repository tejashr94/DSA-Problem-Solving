#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MOD = 1000000007;

    int numberOfSets(int n, int k) {
        vector<vector<long long>> dp(n, vector<long long>(k + 1, 0));
        vector<vector<long long>> prefix(n, vector<long long>(k + 1, 0));

        // 0 segments -> 1 way
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
            prefix[i][0] = i + 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                // Don't use point i as the ending point
                dp[i][j] = dp[i - 1][j];

                // Use i as the right endpoint of a segment
                dp[i][j] += prefix[i - 1][j - 1];
                dp[i][j] %= MOD;

                // Update prefix sum
                prefix[i][j] =
                    (prefix[i - 1][j] + dp[i][j]) % MOD;
            }
        }

        return static_cast<int>(dp[n - 1][k]);
    }
};
