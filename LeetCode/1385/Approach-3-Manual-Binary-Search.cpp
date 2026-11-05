#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool hasCloseValue(const vector<int>& a, int x, int d) {
        int left = 0, right = (int)a.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (a[mid] < x - d) left = mid + 1;
            else if (a[mid] > x + d) right = mid - 1;
            else return true;
        }

        return false;
    }

public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int answer = 0;

        for (int x : arr1) {
            if (!hasCloseValue(arr2, x, d)) answer++;
        }

        return answer;
    }
};

// Time: O(m log m + n log m), Space: O(1) auxiliary
