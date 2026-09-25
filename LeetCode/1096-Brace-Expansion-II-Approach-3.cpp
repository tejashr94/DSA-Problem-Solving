/*
LeetCode 1096 - Brace Expansion II
Approach 3: Recursive parser with explicit expression/term grammar.

Grammar:
expression := term (',' term)*
term       := factor+
factor     := letter | '{' expression '}'

This separates union (expression) from concatenation (term).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    string s;
    int pos;

    set<string> unite(const set<string>& a, const set<string>& b) {
        set<string> r = a;
        r.insert(b.begin(), b.end());
        return r;
    }

    set<string> concat(const set<string>& a, const set<string>& b) {
        set<string> r;
        for (const auto& x : a)
            for (const auto& y : b)
                r.insert(x + y);
        return r;
    }

    set<string> expression() {
        set<string> ans = term();

        while (pos < (int)s.size() && s[pos] == ',') {
            ++pos;
            ans = unite(ans, term());
        }
        return ans;
    }

    set<string> term() {
        set<string> ans = {""};

        while (pos < (int)s.size() && s[pos] != '}' && s[pos] != ',')
            ans = concat(ans, factor());

        return ans;
    }

    set<string> factor() {
        if (s[pos] == '{') {
            ++pos;
            set<string> r = expression();
            ++pos; // '}'
            return r;
        }

        return {string(1, s[pos++])};
    }

public:
    vector<string> braceExpansionII(string expressionInput) {
        s = expressionInput;
        pos = 0;
        set<string> ans = expression();
        return vector<string>(ans.begin(), ans.end());
    }
};
