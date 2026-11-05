#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int answer = 0;

        for (int x : arr1) {
            bool valid = true;
            for (int y : arr2) {
                if (abs(x - y) <= d) {
                    valid = false;
                    break;
                }
            }
            if (valid) answer++;
        }

        return answer;
    }
};

// Time: O(n * m), Space: O(1)
