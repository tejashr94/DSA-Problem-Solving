#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int answer = 0;

        for (int x : arr1) {
            auto it = lower_bound(arr2.begin(), arr2.end(), x);

            bool closeRight = (it != arr2.end() && *it - x <= d);
            bool closeLeft = (it != arr2.begin() && x - *prev(it) <= d);

            if (!closeRight && !closeLeft) answer++;
        }

        return answer;
    }
};

// Time: O(m log m + n log m), Space: O(1) auxiliary
