#include <bits/stdc++.h>
using namespace std;

// Approach 3: Treat every valid substring as an interval.
// Then use the classic interval-scheduling greedy strategy:
// choose the interval that finishes earliest.
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> first(26, -1), last(26, -1);

        for (int i = 0; i < (int)s.size(); ++i) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        vector<pair<int,int>> intervals;

        for (int c = 0; c < 26; ++c) {
            if (first[c] == -1) continue;

            int l = first[c], r = last[c];
            bool valid = true;

            for (int i = l; i <= r; ++i) {
                int x = s[i] - 'a';

                if (first[x] < l) {
                    valid = false;
                    break;
                }

                r = max(r, last[x]);
            }

            if (valid)
                intervals.emplace_back(l, r);
        }

        sort(intervals.begin(), intervals.end(),
             [](const auto& a, const auto& b) {
                 if (a.second != b.second)
                     return a.second < b.second;
                 return a.first > b.first;
             });

        vector<string> answer;
        int lastEnd = -1;

        for (auto [l, r] : intervals) {
            if (l > lastEnd) {
                answer.push_back(s.substr(l, r - l + 1));
                lastEnd = r;
            }
        }

        return answer;
    }
};
