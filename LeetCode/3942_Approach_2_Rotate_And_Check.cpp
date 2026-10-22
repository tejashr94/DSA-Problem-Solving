#include <bits/stdc++.h>
using namespace std;

// Approach 2: Materialize the two circular orientations, then verify their order.
class Solution {
    bool increasingFromZero(const vector<int>& nums, int zero, int step) {
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            int previous = (zero + (i - 1) * step + n) % n;
            int current = (zero + i * step + n) % n;
            if (nums[current] != nums[previous] + 1) return false;
        }
        return true;
    }

public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int zero = find(nums.begin(), nums.end(), 0) - nums.begin();
        int answer = INT_MAX;

        if (increasingFromZero(nums, zero, 1))
            answer = min(answer, min(zero, n - zero + 2));

        if (increasingFromZero(nums, zero, -1))
            answer = min(answer, min(zero + 2, n - zero));

        return answer == INT_MAX ? -1 : answer;
    }
};
