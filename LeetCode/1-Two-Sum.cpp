// LeetCode 1: Two Sum
// Approach: Hash map (one pass)
// Time: O(n), Space: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;
        for (int i = 0; i < (int)nums.size(); ++i) {
            int need = target - nums[i];
            if (index.count(need)) return {index[need], i};
            index[nums[i]] = i;
        }
        return {};
    }
};
