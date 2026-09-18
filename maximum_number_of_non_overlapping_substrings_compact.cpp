#include <bits/stdc++.h>
using namespace std;

// Approach 4: Compact implementation.
// The important observation is that there are only 26 possible
// character intervals. After constructing minimal valid intervals,
// earliest finishing intervals can be selected greedily.
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> l(26, s.size()), r(26, -1);

        for (int i = 0; i < (int)s.size(); ++i) {
            int c = s[i] - 'a';
            l[c] = min(l[c], i);
            r[c] = i;
        }

        vector<pair<int,int>> v;

        for (int c = 0; c < 26; ++c) {
            if (r[c] < 0) continue;

            int a = l[c], b = r[c];
            bool good = true;

            for (int i = a; i <= b; ++i) {
                int x = s[i] - 'a';
                if (l[x] < a) {
                    good = false;
                    break;
                }
                b = max(b, r[x]);
            }

            if (good) v.push_back({a, b});
        }

        sort(v.begin(), v.end(),
             [](auto x, auto y) { return x.second < y.second; });

        vector<string> ans;
        int finish = -1;

        for (auto [a, b] : v) {
            if (a > finish) {
                ans.push_back(s.substr(a, b - a + 1));
                finish = b;
            }
        }

        return ans;
    }
};
