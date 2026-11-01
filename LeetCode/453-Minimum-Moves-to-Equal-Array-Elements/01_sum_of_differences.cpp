// LeetCode 453: Minimum Moves to Equal Array Elements
// Approach 1: Sum of differences from the minimum element.
// Time: O(n), Space: O(1)

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minimum = *min_element(nums.begin(), nums.end());
        int moves = 0;

        for (int num : nums) {
            moves += num - minimum;
        }

        return moves;
    }
};
