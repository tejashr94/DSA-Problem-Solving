#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> ans;

    void dfs(string& s, int open, int close, int n) {
        if (open > n || close > n || close > open)
            return;

        if (open + close == 2 * n) {
            ans.push_back(s);
            return;
        }

        if (open < n) {
            s.push_back('(');
            dfs(s, open + 1, close, n);
            s.pop_back();
        }

        if (close < open) {
            s.push_back(')');
            dfs(s, open, close + 1, n);
            s.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        ans.clear();
        string s;
        dfs(s, 0, 0, n);
        return ans;
    }
};
