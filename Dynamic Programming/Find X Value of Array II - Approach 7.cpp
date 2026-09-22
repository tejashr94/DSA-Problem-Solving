#include <bits/stdc++.h>
using namespace std;

// LeetCode 3525 - Find X Value of Array II
// Approach 7: Segment Tree with fixed-size remainder state.
// Uses a compact Node and an explicit recursive range accumulator.

class Solution {
    struct Node {
        int product = 1;
        array<int, 5> ways{};
    };

    int k, n;
    vector<Node> seg;

    Node join(const Node& a, const Node& b) {
        Node c;
        c.product = (a.product * b.product) % k;

        for (int r = 0; r < k; ++r) {
            c.ways[r] = a.ways[r];
            c.ways[(a.product * r) % k] += b.ways[r];
        }
        return c;
    }

    void build(const vector<int>& a, int p, int l, int r) {
        if (l == r) {
            int rem = a[l] % k;
            seg[p].product = rem;
            seg[p].ways[rem] = 1;
            return;
        }

        int m = (l + r) / 2;
        build(a, p * 2, l, m);
        build(a, p * 2 + 1, m + 1, r);
        seg[p] = join(seg[p * 2], seg[p * 2 + 1]);
    }

    void update(int p, int l, int r, int idx, int value) {
        if (l == r) {
            seg[p] = Node();
            int rem = value % k;
            seg[p].product = rem;
            seg[p].ways[rem] = 1;
            return;
        }

        int m = (l + r) / 2;
        if (idx <= m) update(p * 2, l, m, idx, value);
        else update(p * 2 + 1, m + 1, r, idx, value);

        seg[p] = join(seg[p * 2], seg[p * 2 + 1]);
    }

    Node get(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return seg[p];

        int m = (l + r) / 2;

        if (qr <= m)
            return get(p * 2, l, m, ql, qr);

        if (ql > m)
            return get(p * 2 + 1, m + 1, r, ql, qr);

        Node left = get(p * 2, l, m, ql, qr);
        Node right = get(p * 2 + 1, m + 1, r, ql, qr);
        return join(left, right);
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        this->k = k;
        n = nums.size();
        seg.assign(4 * n + 5, Node());

        build(nums, 1, 0, n - 1);

        vector<int> ans;
        for (const auto& q : queries) {
            update(1, 0, n - 1, q[0], q[1]);
            Node res = get(1, 0, n - 1, q[2], n - 1);
            ans.push_back(res.ways[q[3]]);
        }
        return ans;
    }
};