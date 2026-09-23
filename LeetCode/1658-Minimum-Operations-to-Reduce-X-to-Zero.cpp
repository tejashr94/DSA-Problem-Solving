#include <bits/stdc++.h>
using namespace std;

// LeetCode 1658: Minimum Operations to Reduce X to Zero
// Approach 1: Sliding Window
// Keep the longest subarray with sum = totalSum - x.
// Answer = n - longest subarray length.
// Time: O(n), Space: O(1)

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long total = 0;

        for (int num : nums)
            total += num;

        long long target = total - x;

        if (target == 0) return n;
        if (target < 0) return -1;

        long long sum = 0;
        int left = 0;
        int maxLen = -1;

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
Approach 2: Prefix/Suffix Enumeration
Use prefix sums from the left and suffix sums from the right.
Try every valid number of removals from one side and find the
matching amount needed from the other side.

Time: O(n), Space: O(n).
*/

/*
Approach 3: Prefix Sum + Hash Map
Transform the problem into finding the longest subarray with
sum = totalSum - x. Store prefix sums in a hash map and look
for the required complementary prefix sum.

Time: O(n), Space: O(n).
*/
