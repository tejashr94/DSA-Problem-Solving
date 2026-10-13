// LeetCode 3727: Maximum Alternating Sum of Squares
// Approach: Greedy + Sorting
// Time Complexity: O(n log n)
// Space Complexity: O(1) auxiliary (ignoring sorting implementation)

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> squares;
        squares.reserve(nums.size());

        for (int x : nums) {
            squares.push_back(1LL * x * x);
        }

        sort(squares.begin(), squares.end());

        long long ans = 0;
        int n = static_cast<int>(squares.size());
        int mid = n / 2;

        for (int i = 0; i < mid; ++i) {
            ans -= squares[i];
        }

        for (int i = mid; i < n; ++i) {
            ans += squares[i];
        }

        return ans;
    }
};
