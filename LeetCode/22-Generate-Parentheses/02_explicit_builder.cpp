#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> ans;

    void dfs(string& cur, int open, int close, int n) {
        if (cur.size() == 2 * n) {
            ans.push_back(cur);
            return;
        }

        if (open < n) {
            cur.push_back('(');
            dfs(cur, open + 1, close, n);
            cur.pop_back();
        }

        if (close < open) {
            cur.push_back(')');
            dfs(cur, open, close + 1, n);
            cur.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        ans.clear();
        string cur;
        dfs(cur, 0, 0, n);
        return ans;
    }
};
