// LeetCode 1569: Number of Ways to Reorder Array to Get Same BST
// Approach 3: Recursive BST split + binomial coefficients computed on demand.
// This version stores C(n,k) in a table and memoizes each subproblem by its sequence.
// Time: O(n^2) for partitions/table, plus map-key copying overhead; Space: O(n^2).

class Solution {
    static constexpr long long MOD = 1'000'000'007LL;
    vector<vector<long long>> chooseTable;
    map<vector<int>, long long> memo;

    long long dfs(const vector<int>& nums) {
        auto it = memo.find(nums);
        if (it != memo.end()) return it->second;

        int n = static_cast<int>(nums.size());
        if (n <= 2) return memo[nums] = 1;

        int root = nums[0];
        vector<int> left, right;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < root) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        long long ways = chooseTable[n - 1][left.size()];
        ways = ways * dfs(left) % MOD;
        ways = ways * dfs(right) % MOD;
        return memo[nums] = ways;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        chooseTable.assign(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; ++i) {
            chooseTable[i][0] = chooseTable[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                chooseTable[i][j] =
                    (chooseTable[i - 1][j - 1] + chooseTable[i - 1][j]) % MOD;
            }
        }

        memo.clear();
        return static_cast<int>((dfs(nums) - 1 + MOD) % MOD);
    }
};