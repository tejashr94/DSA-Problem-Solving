#include <bits/stdc++.h>
using namespace std;

// LeetCode 3525 - Find X Value of Array II
// Approach 1: Recursive Segment Tree

class Solution {
    struct Node {
        int prod;
        int cnt[5];
        Node() : prod(1), cnt{0,0,0,0,0} {}
    };

    int k;
    vector<Node> tree;

    Node merge(const Node& a, const Node& b) {
        Node res;
        res.prod = (a.prod * b.prod) % k;

        for (int r = 0; r < k; ++r)
            res.cnt[r] = a.cnt[r];

        for (int r = 0; r < k; ++r) {
            int rem = (a.prod * r) % k;
            res.cnt[rem] += b.cnt[r];
        }

        return res;
    }

    void build(const vector<int>& nums, int p, int l, int r) {
        if (l == r) {
            int rem = nums[l] % k;
            tree[p].prod = rem;
            tree[p].cnt[rem] = 1;
            return;
        }

        int m = (l + r) / 2;
        build(nums, p * 2, l, m);
        build(nums, p * 2 + 1, m + 1, r);
        tree[p] = merge(tree[p * 2], tree[p * 2 + 1]);
    }

    void update(int p, int l, int r, int idx, int value) {
        if (l == r) {
            tree[p] = Node();
            int rem = value % k;
            tree[p].prod = rem;
            tree[p].cnt[rem] = 1;
            return;
        }

        int m = (l + r) / 2;
        if (idx <= m) update(p * 2, l, m, idx, value);
        else update(p * 2 + 1, m + 1, r, idx, value);

        tree[p] = merge(tree[p * 2], tree[p * 2 + 1]);
    }

    Node query(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tree[p];

        int m = (l + r) / 2;
        if (qr <= m) return query(p * 2, l, m, ql, qr);
        if (ql > m) return query(p * 2 + 1, m + 1, r, ql, qr);

        Node a = query(p * 2, l, m, ql, qr);
        Node b = query(p * 2 + 1, m + 1, r, ql, qr);
        return merge(a, b);
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        this->k = k;
        int n = nums.size();
        tree.assign(4 * n + 5, Node());

        build(nums, 1, 0, n - 1);

        vector<int> ans;
        for (const auto& q : queries) {
            update(1, 0, n - 1, q[0], q[1]);
            ans.push_back(query(1, 0, n - 1, q[2], n - 1).cnt[q[3]]);
        }
        return ans;
    }
};