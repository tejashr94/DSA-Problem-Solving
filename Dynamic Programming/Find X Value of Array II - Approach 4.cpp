#include <bits/stdc++.h>
using namespace std;

// LeetCode 3525 - Find X Value of Array II
// Approach 4: Direct prefix scan
// Educational baseline. After each update, scan [start, n-1]
// and count prefixes whose product % k == x.

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        vector<int> ans;

        for (const auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            nums[index] = value;

            int product = 1;
            int count = 0;

            for (int i = start; i < (int)nums.size(); ++i) {
                product = (product * (nums[i] % k)) % k;
                if (product == x)
                    ++count;
            }

            ans.push_back(count);
        }

        return ans;
    }
};