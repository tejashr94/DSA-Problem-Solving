// LeetCode 453: Minimum Moves to Equal Array Elements
// Approach 2: Sort the array; the first element is the minimum.
// Time: O(n log n), Space: O(1) auxiliary (sorting implementation may use stack space).

class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int moves = 0;
        for (int num : nums) {
            moves += num - nums[0];
        }

        return moves;
    }
};
