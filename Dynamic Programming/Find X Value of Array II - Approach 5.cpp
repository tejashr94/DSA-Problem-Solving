#include <bits/stdc++.h>
using namespace std;

// LeetCode 3525 - Find X Value of Array II
// Approach 5: Square-root decomposition
// Each block stores its whole product and prefix counts by remainder.
// Updates rebuild one block; queries combine complete blocks and
// scan only the partial boundaries.

class Solution {
    struct Block {
        int prod = 1;
        array<int, 5> cnt{};
    };

    int k, n, B;
    vector<Block> blocks;

    Block makeBlock(const vector<int>& a, int l, int r) {
        Block b;
        int prod = 1;

        for (int i = l; i <= r; ++i) {
            prod = (prod * (a[i] % k)) % k;
            ++b.cnt[prod];
        }

        b.prod = prod;
        return b;
    }

    void rebuild(vector<int>& nums, int id) {
        int l = id * B;
        int r = min(n - 1, l + B - 1);
        blocks[id] = makeBlock(nums, l, r);
    }

    void appendElement(int& product, int value, int& answer, int x) {
        product = (product * (value % k)) % k;
        if (product == x)
            ++answer;
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        this->k = k;
        n = nums.size();

        B = max(1, (int)sqrt(n));
        int m = (n + B - 1) / B;
        blocks.assign(m, Block());

        for (int i = 0; i < m; ++i)
            rebuild(nums, i);

        vector<int> ans;

        for (const auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            nums[index] = value;
            rebuild(nums, index / B);

            int product = 1;
            int count = 0;
            int i = start;

            // Left partial block.
            int blockEnd = min(n, ((i / B) + 1) * B);
            while (i < blockEnd) {
                appendElement(product, nums[i], count, x);
                ++i;
            }

            // Complete blocks.
            while (i + B <= n) {
                int id = i / B;

                for (int r = 0; r < k; ++r) {
                    int rem = (product * r) % k;
                    if (rem == x)
                        count += blocks[id].cnt[r];
                }

                product = (product * blocks[id].prod) % k;
                i += B;
            }

            // Right partial block.
            while (i < n) {
                appendElement(product, nums[i], count, x);
                ++i;
            }

            ans.push_back(count);
        }

        return ans;
    }
};