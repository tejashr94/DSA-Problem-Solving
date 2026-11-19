// LeetCode 26: Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int k = 1;
        for (int i = 1; i < (int)nums.size(); ++i) {
            if (nums[i] != nums[k - 1]) nums[k++] = nums[i];
        }
        return k;
    }
};