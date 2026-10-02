#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int write = m + n - 1;
        int i = m - 1;

        // Place nums2 directly when nums1 is exhausted.
        while (n > 0) {
            if (i >= 0 && nums1[i] > nums2[n - 1])
                nums1[write--] = nums1[i--];
            else
                nums1[write--] = nums2[--n];
        }
    }
};
