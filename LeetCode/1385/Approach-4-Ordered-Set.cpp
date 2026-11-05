#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        set<int> values(arr2.begin(), arr2.end());
        int answer = 0;

        for (int x : arr1) {
            auto it = values.lower_bound(x);

            bool closeRight = (it != values.end() && *it - x <= d);
            bool closeLeft = (it != values.begin() && x - *prev(it) <= d);

            if (!closeRight && !closeLeft) answer++;
        }

        return answer;
    }
};

// Time: O(m log m + n log m), Space: O(m)
