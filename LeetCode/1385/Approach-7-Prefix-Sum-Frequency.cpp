#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        // LeetCode 1385 guarantees values in the range [1, 1000].
        vector<int> prefix(1002, 0);

        for (int x : arr2) prefix[x]++;

        for (int i = 1; i <= 1000; i++) {
            prefix[i] += prefix[i - 1];
        }

        int answer = 0;

        for (int x : arr1) {
            int low = max(1, x - d);
            int high = min(1000, x + d);
            int countInRange = prefix[high] - prefix[low - 1];

            if (countInRange == 0) answer++;
        }

        return answer;
    }
};

// Time: O(n + m + 1000), Space: O(1000)
