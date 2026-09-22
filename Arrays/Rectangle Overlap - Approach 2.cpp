#include <bits/stdc++.h>
using namespace std;

// LeetCode 836 - Rectangle Overlap
// Approach 2: Detect the non-overlap cases.
// Rectangles overlap iff none of the four separating conditions holds.

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        bool separated =
            rec1[2] <= rec2[0] ||   // rec1 is left of rec2
            rec2[2] <= rec1[0] ||   // rec2 is left of rec1
            rec1[3] <= rec2[1] ||   // rec1 is below rec2
            rec2[3] <= rec1[1];     // rec2 is below rec1

        return !separated;
    }
};