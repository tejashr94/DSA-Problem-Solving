#include <bits/stdc++.h>
using namespace std;

// Approach 3: Count breaks in the cyclic sequence in each direction.
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int zero = find(nums.begin(), nums.end(), 0) - nums.begin();
        bool forward = true, backward = true;

        for (int i = 1; i < n; ++i) {
            int right = (zero + i) % n;
            int rightPrev = (zero + i - 1) % n;
            if (nums[right] != nums[rightPrev] + 1) forward = false;

            int left = (zero - i + n) % n;
            int leftPrev = (zero - i + 1 + n) % n;
            if (nums[left] != nums[leftPrev] + 1) backward = false;
        }

        int answer = INT_MAX;
        if (forward) answer = min(answer, min(zero, n - zero + 2));
        if (backward) answer = min(answer, min(zero + 2, n - zero));
        return answer == INT_MAX ? -1 : answer;
    }
};
