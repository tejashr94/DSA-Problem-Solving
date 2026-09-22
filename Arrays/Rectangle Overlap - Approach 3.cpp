#include <bits/stdc++.h>
using namespace std;

// LeetCode 836 - Rectangle Overlap
// Approach 3: Compute the intersection rectangle and check its area.
// Touching only at an edge/corner gives zero area and is not overlap.

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        long long x1 = max(rec1[0], rec2[0]);
        long long y1 = max(rec1[1], rec2[1]);
        long long x2 = min(rec1[2], rec2[2]);
        long long y2 = min(rec1[3], rec2[3]);

        long long width = max(0LL, x2 - x1);
        long long height = max(0LL, y2 - y1);

        return width * height > 0;
    }
};