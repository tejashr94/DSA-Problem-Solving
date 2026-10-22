#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int zero = find(nums.begin(), nums.end(), 0) - nums.begin();

        auto isSortedCircular = [&](int direction) {
            for (int i = 1; i < n; ++i) {
                int previous = (zero + (i - 1) * direction + n) % n;
                int current = (zero + i * direction + n) % n;
                if (nums[previous] > nums[current]) return false;
            }
            return true;
        };

        int answer = INT_MAX;

        if (isSortedCircular(1)) {
            answer = min(answer, zero);
            answer = min(answer, n - zero + 2);
        }

        if (isSortedCircular(-1)) {
            answer = min(answer, zero + 2);
            answer = min(answer, n - zero);
        }

        return answer == INT_MAX ? -1 : answer;
    }
};
