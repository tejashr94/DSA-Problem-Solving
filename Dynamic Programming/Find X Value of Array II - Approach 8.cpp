#include <bits/stdc++.h>
using namespace std;

// LeetCode 3525 - Find X Value of Array II
// Approach 8: Power-of-two iterative tree with a dedicated range combiner.

class Solution {
    struct Node {
        int product = 1;
        int cnt[5] = {};
    };

    int k, n, base;
    vector<Node> tree;

    Node combine(const Node& a, const Node& b) {
        Node res;
        res.product = (a.product * b.product) % k;

        for (int r = 0; r < k; ++r) {
            res.cnt[r] = a.cnt[r];
            res.cnt[(a.product * r) % k] += b.cnt[r];
        }
        return res;
    }

    void put(int p, int value) {
        tree[p] = Node();
        int rem = value % k;
        tree[p].product = rem;
        tree[p].cnt[rem] = 1;
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        this->k = k;
        n = nums.size();

        base = 1;
        while (base < n) base <<= 1;

        tree.assign(2 * base, Node());

        for (int i = 0; i < n; ++i)
            put(base + i, nums[i]);

        for (int p = base - 1; p >= 1; --p)
            tree[p] = combine(tree[p << 1], tree[p << 1 | 1]);

        auto update = [&](int idx, int value) {
            int p = base + idx;
            put(p, value);

            for (p >>= 1; p; p >>= 1)
                tree[p] = combine(tree[p << 1], tree[p << 1 | 1]);
        };

        auto range = [&](int l, int r) {
            Node left, right;
            bool hasLeft = false, hasRight = false;

            l += base;
            r += base + 1;

            while (l < r) {
                if (l & 1) {
                    left = hasLeft ? combine(left, tree[l]) : tree[l];
                    hasLeft = true;
                    ++l;
                }

                if (r & 1) {
                    --r;
                    right = hasRight ? combine(tree[r], right) : tree[r];
                    hasRight = true;
                }

                l >>= 1;
                r >>= 1;
            }

            if (!hasLeft) return right;
            if (!hasRight) return left;
            return combine(left, right);
        };

        vector<int> ans;
        for (const auto& q : queries) {
            update(q[0], q[1]);
            ans.push_back(range(q[2], n - 1).cnt[q[3]]);
        }

        return ans;
    }
};