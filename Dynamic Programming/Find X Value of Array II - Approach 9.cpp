#include <bits/stdc++.h>
using namespace std;

// LeetCode 3525 - Find X Value of Array II
// Approach 9: Block decomposition with explicit block prefix states.
// Updates rebuild one block; complete blocks are merged using their
// stored product and prefix-remainder counts.

class Solution {
    struct Block {
        int product = 1;
        array<int, 5> cnt{};
    };

    int n, k, blockSize;
    vector<Block> blocks;

    Block buildBlock(const vector<int>& a, int l, int r) {
        Block b;
        int product = 1;

        for (int i = l; i <= r; ++i) {
            product = (product * (a[i] % k)) % k;
            ++b.cnt[product];
        }

        b.product = product;
        return b;
    }

    void rebuild(vector<int>& nums, int id) {
        int l = id * blockSize;
        int r = min(n - 1, l + blockSize - 1);
        blocks[id] = buildBlock(nums, l, r);
    }

    void add(int& product, int value, int x, int& answer) {
        product = (product * (value % k)) % k;
        if (product == x)
            ++answer;
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        this->k = k;
        n = nums.size();

        blockSize = max(1, (int)sqrt(n));
        int blockCount = (n + blockSize - 1) / blockSize;
        blocks.resize(blockCount);

        for (int b = 0; b < blockCount; ++b)
            rebuild(nums, b);

        vector<int> ans;

        for (const auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            nums[index] = value;
            rebuild(nums, index / blockSize);

            int product = 1;
            int answer = 0;
            int i = start;

            // Partial first block.
            int firstEnd = min(n, ((i / blockSize) + 1) * blockSize);
            while (i < firstEnd) {
                add(product, nums[i], x, answer);
                ++i;
            }

            // Complete blocks.
            while (i + blockSize <= n) {
                int id = i / blockSize;

                for (int r = 0; r < k; ++r) {
                    if ((product * r) % k == x)
                        answer += blocks[id].cnt[r];
                }

                product = (product * blocks[id].product) % k;
                i += blockSize;
            }

            // Final partial block.
            while (i < n) {
                add(product, nums[i], x, answer);
                ++i;
            }

            ans.push_back(answer);
        }

        return ans;
    }
};