/*
LeetCode 1096 - Brace Expansion II

Problem:
Given a valid expression representing a set of lowercase words, return all words
represented by the expression in lexicographical order.

Approach 1:
Recursive descent parsing using sets.
- Comma => union
- Adjacent expressions => Cartesian-product concatenation
- Braces => recursively parse contents
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    set<string> add(const set<string>& a, const set<string>& b) {
        set<string> res = a;
        res.insert(b.begin(), b.end());
        return res;
    }

    set<string> multiply(const set<string>& a, const set<string>& b) {
        set<string> res;
        for (const string& x : a)
            for (const string& y : b)
                res.insert(x + y);
        return res;
    }

    set<string> parse(const string& s, int& i) {
        set<string> result, current = {""};

        while (i < (int)s.size() && s[i] != '}') {
            if (s[i] == ',') {
                result = add(result, current);
                current = {""};
                ++i;
            } else if (s[i] == '{') {
                ++i;
                set<string> inside = parse(s, i);
                current = multiply(current, inside);
                ++i; // '}'
            } else {
                set<string> letter = {string(1, s[i])};
                current = multiply(current, letter);
                ++i;
            }
        }

        return add(result, current);
    }

public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> ans = parse(expression, i);
        return vector<string>(ans.begin(), ans.end());
    }
};
