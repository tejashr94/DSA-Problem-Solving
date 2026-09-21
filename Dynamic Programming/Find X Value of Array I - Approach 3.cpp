#include <bits/stdc++.h>
using namespace std;

// Since k <= 5, keep only k product-remainder states.
// cnt[remainder] = number of subarrays ending at the previous index.
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> cnt(k), result(k);

        for (int value : nums) {
            int x = value % k;
            vector<long long> updated(k);

            updated[x] = 1;  // [current element]

            for (int rem = 0; rem < k; ++rem) {
                updated[(rem * x) % k] += cnt[rem];
            }

            for (int rem = 0; rem < k; ++rem) {
                result[rem] += updated[rem];
            }

            cnt = updated;
        }

        return result;
    }
};
