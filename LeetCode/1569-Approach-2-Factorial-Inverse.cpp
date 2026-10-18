// LeetCode 1569: Number of Ways to Reorder Array to Get Same BST
// Approach 2: Recursion + memoized combinations using factorials and modular inverses
// Time: O(n^2) due to recursive partitioning, Space: O(n^2) overall.

class Solution {
    static constexpr long long MOD = 1'000'000'007LL;
    vector<long long> fact, invFact;

    long long modPow(long long a, long long e) {
        long long result = 1;
        while (e > 0) {
            if (e & 1) result = result * a % MOD;
            a = a * a % MOD;
            e >>= 1;
        }
        return result;
    }

    long long choose(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
    }

    long long dfs(const vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        if (n <= 2) return 1;

        vector<int> left, right;
        int root = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] < root) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        long long ways = choose(n - 1, static_cast<int>(left.size()));
        ways = ways * dfs(left) % MOD;
        ways = ways * dfs(right) % MOD;
        return ways;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        fact.assign(n + 1, 1);
        invFact.assign(n + 1, 1);

        for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i % MOD;
        invFact[n] = modPow(fact[n], MOD - 2);
        for (int i = n; i > 0; --i) invFact[i - 1] = invFact[i] * i % MOD;

        return static_cast<int>((dfs(nums) - 1 + MOD) % MOD);
    }
};