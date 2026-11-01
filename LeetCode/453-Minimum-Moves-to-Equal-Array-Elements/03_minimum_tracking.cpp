// LeetCode 453: Minimum Moves to Equal Array Elements
// Approach 3: Track the minimum and sum in one pass.
// Time: O(n), Space: O(1)

class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long sum = 0;
        int minimum = INT_MAX;

        for (int num : nums) {
            sum += num;
            minimum = min(minimum, num);
        }

        return static_cast<int>(sum - 1LL * nums.size() * minimum);
    }
};
