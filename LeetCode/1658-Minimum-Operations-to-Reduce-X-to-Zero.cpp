// LeetCode 1658 - Minimum Operations to Reduce X to Zero
// Approach 1: Sliding Window | O(n) time | O(1) space
// Find the longest subarray with sum totalSum - x; answer = n - length.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long total = 0;
        for (int v : nums) total += v;

        long long target = total - x;
        if (target == 0) return n;
        if (target < 0) return -1;

        long long sum = 0;
        int left = 0, maxLen = -1;

        for (int right = 0; right < n; ++right) {
            sum += nums[right];
            while (sum > target && left <= right) {
                sum -= nums[left++];
            }
            if (sum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return maxLen == -1 ? -1 : n - maxLen;
    }
};

/*
Approach 2: Prefix/Suffix Enumeration
Use prefix and suffix sums to enumerate how many values are removed
from each end and check matching sums.
Time: O(n), Space: O(n).

Approach 3: Prefix Sum + Hash Map
Find the longest subarray whose sum is totalSum - x using prefix sums.
Time: O(n), Space: O(n).
*/
