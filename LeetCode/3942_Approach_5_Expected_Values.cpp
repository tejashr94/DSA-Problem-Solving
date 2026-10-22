#include <bits/stdc++.h>
using namespace std;

// Approach 5: Compare each position against the value expected from zero.
class Solution {
    bool matches(const vector<int>& nums, int zero, int direction) {
        int n = nums.size();
        for (int offset = 0; offset < n; ++offset) {
            int index = (zero + direction * offset + n) % n;
            if (nums[index] != offset) return false;
        }
        return true;
    }

public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int zero = find(nums.begin(), nums.end(), 0) - nums.begin();

        int answer = INT_MAX;
        if (matches(nums, zero, 1))
            answer = min({answer, zero, n - zero + 2});
        if (matches(nums, zero, -1))
            answer = min({answer, zero + 2, n - zero});

        return answer == INT_MAX ? -1 : answer;
    }
};
