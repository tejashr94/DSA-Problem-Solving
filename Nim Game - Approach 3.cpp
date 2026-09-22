class Solution {
public:
    bool canWinNim(int n) {
        bool dp[4] = {false, true, true, true};
        return dp[n % 4];
    }
};
