#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int distanceValue = 0;

        for (int i = 0; i < arr1.size(); i++) {
            bool isValid = true;

            // arr1[i] must be farther than d from every element in arr2.
            for (int j = 0; j < arr2.size(); j++) {
                if (abs(arr1[i] - arr2[j]) <= d) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                distanceValue++;
            }
        }

        return distanceValue;
    }
};
