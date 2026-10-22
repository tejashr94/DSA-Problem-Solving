#include <bits/stdc++.h>
using namespace std;

// Approach 6: Compact O(n) scan with early rejection for each direction.
class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int n = (int)nums.size();
        const int p = (int)(find(nums.begin(), nums.end(), 0) - nums.begin());

        auto check = [&](int dir) -> bool {
            int expected = 0;
            for (int k = 0; k < n; ++k, ++expected) {
                int i = (p + dir * k + n) % n;
                if (nums[i] != expected) return false;
            }
            return true;
        };

        int best = INT_MAX;
        if (check(1)) best = min(best, min(p, n - p + 2));
        if (check(-1)) best = min(best, min(p + 2, n - p));
        return best == INT_MAX ? -1 : best;
    }
};
