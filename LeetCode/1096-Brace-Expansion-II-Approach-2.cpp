/*
LeetCode 1096 - Brace Expansion II
Approach 2: Stack-based expression evaluation.

Represent each parsed part as a set of strings.
- On '{', start a new scope.
- On ',', finish the current factor and union it into the scope result.
- On a letter, concatenate it with the current factor.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    set<string> product(const set<string>& a, const set<string>& b) {
        set<string> out;
        for (const auto& x : a)
            for (const auto& y : b)
                out.insert(x + y);
        return out;
    }

public:
    vector<string> braceExpansionII(string s) {
        vector<set<string>> sumStack;
        vector<set<string>> productStack;

        set<string> sum, productSet = {""};

        auto flushProduct = [&]() {
            sum.insert(productSet.begin(), productSet.end());
            productSet = {""};
        };

        for (char ch : s) {
            if (ch == '{') {
                sumStack.push_back(sum);
                productStack.push_back(productSet);
                sum.clear();
                productSet = {""};
            } 
            else if (ch == ',') {
                flushProduct();
            } 
            else if (ch == '}') {
                flushProduct();

                set<string> inside = sum;
                set<string> prefix = productStack.back();
                sum = sumStack.back();
                productSet = product(prefix, inside);

                sumStack.pop_back();
                productStack.pop_back();
            } 
            else {
                productSet = product(productSet, {string(1, ch)});
            }
        }

        flushProduct();
        return vector<string>(sum.begin(), sum.end());
    }
};
