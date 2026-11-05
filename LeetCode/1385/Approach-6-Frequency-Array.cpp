#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        // LeetCode 1385 guarantees values in the range [1, 1000].
        vector<int> frequency(1002, 0);
        for (int x : arr2) frequency[x]++;

        int answer = 0;

        for (int x : arr1) {
            bool valid = true;
            int low = max(1, x - d);
            int high = min(1000, x + d);

            for (int value = low; value <= high; value++) {
                if (frequency[value] > 0) {
                    valid = false;
                    break;
                }
            }

            if (valid) answer++;
        }

        return answer;
    }
};

// Time: O(m + n * min(1000, 2d + 1)), Space: O(1000)
