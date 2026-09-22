#include <bits/stdc++.h>
using namespace std;

// LeetCode 3525 - Find X Value of Array II
// Approach 6: Segment tree with a compact monoid.
// The state is represented by {product, prefix-count vector}.
// Query is performed iteratively while preserving left-to-right order.

class Solution {
    struct Node {
        int prod = 1;
        array<int, 5> pref{};
    };

    int k, n, size;
    vector<Node> tree;

    Node combine(const Node& a, const Node& b) {
        Node c;
        c.prod = (a.prod * b.prod) % k;

        for (int r = 0; r < k; ++r) {
            c.pref[r] = a.pref[r];
            c.pref[(a.prod * r) % k] += b.pref[r];
        }

        return c;
    }

    void assignLeaf(int p, int value) {
        tree[p] = Node();
        int rem = value % k;
        tree[p].prod = rem;
        tree[p].pref[rem] = 1;
    }

    Node rangeQuery(int l, int r) {
        Node left, right;
        bool leftUsed = false, rightUsed = false;

        l += size;
        r += size + 1;

        while (l < r) {
            if (l & 1) {
                left = leftUsed ? combine(left, tree[l]) : tree[l];
                leftUsed = true;
                ++l;
            }

            if (r & 1) {
                --r;
                right = rightUsed ? combine(tree[r], right) : tree[r];
                rightUsed = true;
            }

            l >>= 1;
            r >>= 1;
        }

        if (!leftUsed) return right;
        if (!rightUsed) return left;
        return combine(left, right);
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        this->k = k;
        n = nums.size();

        size = 1;
        while (size < n)
            size <<= 1;

        tree.assign(2 * size, Node());

        for (int i = 0; i < n; ++i)
            assignLeaf(size + i, nums[i]);

        for (int p = size - 1; p >= 1; --p)
            tree[p] = combine(tree[p << 1], tree[p << 1 | 1]);

        vector<int> ans;

        for (const auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            int p = size + index;
            assignLeaf(p, value);

            for (p >>= 1; p; p >>= 1)
                tree[p] = combine(tree[p << 1], tree[p << 1 | 1]);

            Node res = rangeQuery(start, n - 1);
            ans.push_back(res.pref[x]);
        }

        return ans;
    }
};