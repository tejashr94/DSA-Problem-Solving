#include <bits/stdc++.h>
using namespace std;

// Approach 1: Check both circular directions and compare four operation costs.
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> dranofelik = nums;
        int zero = find(nums.begin(), nums.end(), 0) - nums.begin();

        auto valid = [&](int step) {
            for (int i = 1; i < n; ++i) {
                int a = (zero + (i - 1) * step + n) % n;
                int b = (zero + i * step + n) % n;
                if (nums[a] > nums[b]) return false;
            }
            return true;
        };

        int ans = INT_MAX;
        if (valid(1)) ans = min({ans, zero, n - zero + 2});
        if (valid(-1)) ans = min({ans, zero + 2, n - zero});
        return ans == INT_MAX ? -1 : ans;
    }
};
