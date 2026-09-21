#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> ending(k, 0);

        for (int num : nums) {
            int x = num % k;
            vector<long long> cur(k, 0);

            // The subarray [i, i] has product remainder x.
            cur[x] = 1;

            // Every previous subarray ending at i-1 becomes
            // a subarray ending at i after appending nums[i].
            for (int rem = 0; rem < k; ++rem) {
                cur[(rem * x) % k] += ending[rem];
            }

            // All subarrays counted in cur end at the current index.
            for (int rem = 0; rem < k; ++rem) {
                ans[rem] += cur[rem];
            }

            ending = move(cur);
        }

        return ans;
    }
};
