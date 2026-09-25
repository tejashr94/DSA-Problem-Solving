/*
LeetCode 1096 - Brace Expansion II
Approach 4: Recursive evaluation using unordered_set for faster average insertion.

The grammar is handled by parsing a union at each brace level and performing
Cartesian-product concatenation between adjacent factors.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_set<string> combine(const unordered_set<string>& a,
                                   const unordered_set<string>& b) {
        unordered_set<string> out;
        out.reserve(a.size() * b.size());
        for (const auto& x : a)
            for (const auto& y : b)
                out.insert(x + y);
        return out;
    }

    unordered_set<string> parse(const string& s, int& i) {
        unordered_set<string> result, current = {""};

        while (i < (int)s.size() && s[i] != '}') {
            if (s[i] == ',') {
                result.insert(current.begin(), current.end());
                current = {""};
                ++i;
            } else if (s[i] == '{') {
                ++i;
                auto inside = parse(s, i);
                current = combine(current, inside);
                ++i;
            } else {
                current = combine(current, {string(1, s[i])});
                ++i;
            }
        }

        result.insert(current.begin(), current.end());
        return result;
    }

public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        auto values = parse(expression, i);
        vector<string> ans(values.begin(), values.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};
