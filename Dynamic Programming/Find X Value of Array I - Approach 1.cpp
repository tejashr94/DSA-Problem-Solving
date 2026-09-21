#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> dp(k, 0), ans(k, 0);

        for (int num : nums) {
            int x = num % k;
            vector<long long> next(k, 0);

            // Start a new subarray with the current element.
            next[x]++;

            // Extend every subarray ending at the previous position.
            for (int r = 0; r < k; ++r) {
                if (dp[r] == 0) continue;
                next[(r * x) % k] += dp[r];
            }

            for (int r = 0; r < k; ++r) {
                ans[r] += next[r];
            }

            dp.swap(next);
        }

        return ans;
    }
};
