// LeetCode 22: Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/

#include <string>
#include <vector>
using namespace std;

class Solution {
    void backtrack(vector<string>& ans, string cur, int open, int close, int n) {
        if (cur.size() == 2 * n) {
            ans.push_back(cur);
            return;
        }
        if (open < n) backtrack(ans, cur + '(', open + 1, close, n);
        if (close < open) backtrack(ans, cur + ')', open, close + 1, n);
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(ans, "", 0, 0, n);
        return ans;
    }
};