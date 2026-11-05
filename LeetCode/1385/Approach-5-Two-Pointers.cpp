#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());

        int j = 0, answer = 0;

        for (int x : arr1) {
            while (j < (int)arr2.size() && arr2[j] < x - d) {
                j++;
            }

            if (j == (int)arr2.size() || arr2[j] > x + d) {
                answer++;
            }
        }

        return answer;
    }
};

// Time: O(n log n + m log m), Space: O(1) auxiliary
