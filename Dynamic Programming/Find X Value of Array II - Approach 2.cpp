#include <bits/stdc++.h>
using namespace std;

// LeetCode 3525 - Find X Value of Array II
// Approach 2: Iterative Segment Tree

class Solution {
    struct Node {
        int prod = 1;
        array<int, 5> cnt{};
    };

    int k, n, size;
    vector<Node> st;

    Node merge(const Node& a, const Node& b) {
        Node c;
        c.prod = (a.prod * b.prod) % k;

        for (int r = 0; r < k; ++r)
            c.cnt[r] = a.cnt[r];

        for (int r = 0; r < k; ++r)
            c.cnt[(a.prod * r) % k] += b.cnt[r];

        return c;
    }

    void setLeaf(int p, int value) {
        st[p] = Node();
        int rem = value % k;
        st[p].prod = rem;
        st[p].cnt[rem] = 1;
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        this->k = k;
        n = nums.size();

        size = 1;
        while (size < n) size <<= 1;
        st.assign(2 * size, Node());

        for (int i = 0; i < n; ++i)
            setLeaf(size + i, nums[i]);

        for (int p = size - 1; p; --p)
            st[p] = merge(st[p << 1], st[p << 1 | 1]);

        auto update = [&](int pos, int value) {
            int p = size + pos;
            setLeaf(p, value);
            for (p >>= 1; p; p >>= 1)
                st[p] = merge(st[p << 1], st[p << 1 | 1]);
        };

        auto query = [&](int l, int r) {
            Node leftAcc, rightAcc;
            bool hasLeft = false, hasRight = false;

            int L = size + l;
            int R = size + r + 1;

            while (L < R) {
                if (L & 1) {
                    leftAcc = hasLeft ? merge(leftAcc, st[L]) : st[L];
                    hasLeft = true;
                    ++L;
                }
                if (R & 1) {
                    --R;
                    rightAcc = hasRight ? merge(st[R], rightAcc) : st[R];
                    hasRight = true;
                }
                L >>= 1;
                R >>= 1;
            }

            if (!hasLeft) return rightAcc;
            if (!hasRight) return leftAcc;
            return merge(leftAcc, rightAcc);
        };

        vector<int> ans;
        for (const auto& q : queries) {
            update(q[0], q[1]);
            ans.push_back(query(q[2], n - 1).cnt[q[3]]);
        }
        return ans;
    }
};