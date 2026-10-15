// LeetCode 2913: Subarrays Distinct Element Sum of Squares I
// Approach: Enumerate all subarrays and maintain element frequencies.
// Time Complexity: O(n^2) average
// Space Complexity: O(n)

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            unordered_map<int, int> freq;
            int distinct = 0;

            for (int j = i; j < n; ++j) {
                if (++freq[nums[j]] == 1) {
                    ++distinct;
                }

                ans += distinct * distinct;
            }
        }

        return ans;
    }
};
