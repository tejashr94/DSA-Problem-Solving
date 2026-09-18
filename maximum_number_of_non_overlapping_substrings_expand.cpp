#include <bits/stdc++.h>
using namespace std;

// Approach 2: Expand a range until it contains every occurrence
// of every character inside it.
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> L(26, n), R(26, -1);

        for (int i = 0; i < n; ++i) {
            L[s[i] - 'a'] = min(L[s[i] - 'a'], i);
            R[s[i] - 'a'] = i;
        }

        vector<pair<int,int>> valid;

        for (int c = 0; c < 26; ++c) {
            if (R[c] == -1) continue;

            int left = L[c];
            int right = R[c];

            for (int i = left; i <= right; ++i) {
                int x = s[i] - 'a';

                if (L[x] < left) {
                    right = -1;
                    break;
                }

                right = max(right, R[x]);
            }

            if (right != -1)
                valid.push_back({left, right});
        }

        sort(valid.begin(), valid.end(),
             [](const auto& a, const auto& b) {
                 return a.second < b.second;
             });

        vector<string> result;
        int previousEnd = -1;

        for (auto [left, right] : valid) {
            if (left > previousEnd) {
                result.push_back(s.substr(left, right - left + 1));
                previousEnd = right;
            }
        }

        return result;
    }
};
