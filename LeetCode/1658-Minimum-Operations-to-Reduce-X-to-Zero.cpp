#include <bits/stdc++.h>
using namespace std;

// LeetCode 1658: Minimum Operations to Reduce X to Zero
// Approach 1: Sliding Window
// Find the longest subarray with sum = totalSum - x.
// Answer = n - longest subarray length.
// Time: O(n), Space: O(1)

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        long long total = 0;
        for (int num : nums) total += num;

        long long target = total - x;

        if (target == 0) return n;
        if (target < 0) return -1;

        long long sum = 0;
        int left = 0, maxLen = -1;

        for (int right = 0; right < n; right++) {
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
Approach 2: Prefix/Suffix Combination
A direct alternative is to enumerate how many elements are removed
from the left and use a two-pointer/prefix-sum search for the right side.
With positive nums, this can also be implemented in O(n).

Approach 3: Prefix Sum + Hash Map
Store prefix sums and search for a complementary sum corresponding
to the removable boundary. This works in O(n) time and O(n) space.
*/
