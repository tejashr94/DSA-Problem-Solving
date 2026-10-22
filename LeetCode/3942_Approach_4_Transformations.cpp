#include <bits/stdc++.h>
using namespace std;

// Approach 4: Rotate zero to the front, then test the forward and reverse order.
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int zero = find(nums.begin(), nums.end(), 0) - nums.begin();
        vector<int> rotated = nums;
        rotate(rotated.begin(), rotated.begin() + zero, rotated.end());

        bool forward = true;
        for (int i = 0; i < n; ++i) {
            if (rotated[i] != i) {
                forward = false;
                break;
            }
        }

        // For the other orientation, traverse the original array left from zero.
        bool backward = true;
        for (int i = 0; i < n; ++i) {
            int idx = (zero - i + n) % n;
            if (nums[idx] != i) {
                backward = false;
                break;
            }
        }

        int answer = INT_MAX;
        if (forward) answer = min(answer, min(zero, n - zero + 2));
        if (backward) answer = min(answer, min(zero + 2, n - zero));
        return answer == INT_MAX ? -1 : answer;
    }
};
