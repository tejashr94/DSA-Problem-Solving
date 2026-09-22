#include <bits/stdc++.h>
using namespace std;

// LeetCode 3525 - Find X Value of Array II
// Approach 3: Compact recursive segment tree

class Solution {
    struct Node {
        int prod = 1;
        array<int, 5> pref{};
    };

    int k, n;
    vector<Node> tr;

    Node mergeNode(const Node& a, const Node& b) {
        Node c;
        c.prod = (a.prod * b.prod) % k;

        for (int r = 0; r < k; ++r)
            c.pref[r] = a.pref[r];

        for (int r = 0; r < k; ++r)
            c.pref[(a.prod * r) % k] += b.pref[r];

        return c;
    }

    void build(const vector<int>& a, int p, int l, int r) {
        if (l == r) {
            int rem = a[l] % k;
            tr[p].prod = rem;
            tr[p].pref[rem] = 1;
            return;
        }

        int m = (l + r) >> 1;
        build(a, p << 1, l, m);
        build(a, p << 1 | 1, m + 1, r);
        tr[p] = mergeNode(tr[p << 1], tr[p << 1 | 1]);
    }

    void change(int p, int l, int r, int idx, int value) {
        if (l == r) {
            tr[p] = Node();
            int rem = value % k;
            tr[p].prod = rem;
            tr[p].pref[rem] = 1;
            return;
        }

        int m = (l + r) >> 1;
        if (idx <= m) change(p << 1, l, m, idx, value);
        else change(p << 1 | 1, m + 1, r, idx, value);

        tr[p] = mergeNode(tr[p << 1], tr[p << 1 | 1]);
    }

    Node get(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tr[p];

        int m = (l + r) >> 1;
        if (qr <= m) return get(p << 1, l, m, ql, qr);
        if (ql > m) return get(p << 1 | 1, m + 1, r, ql, qr);

        return mergeNode(
            get(p << 1, l, m, ql, qr),
            get(p << 1 | 1, m + 1, r, ql, qr)
        );
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        this->k = k;
        n = nums.size();

        tr.assign(4 * n + 4, Node());
        build(nums, 1, 0, n - 1);

        vector<int> ans;
        for (const auto& q : queries) {
            change(1, 0, n - 1, q[0], q[1]);
            ans.push_back(get(1, 0, n - 1, q[2], n - 1).pref[q[3]]);
        }
        return ans;
    }
};