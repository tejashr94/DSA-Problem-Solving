#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> oddPalindromes(const string& s) {
        int n = s.size();
        vector<int> d1(n);
        for (int i = 0, l = 0, r = -1; i < n; ++i) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) ++k;
            d1[i] = k;
            if (i + k - 1 > r) l = i - k + 1, r = i + k - 1;
        }
        return d1;
    }

    vector<int> evenPalindromes(const string& s) {
        int n = s.size();
        vector<int> d2(n);
        for (int i = 0, l = 0, r = -1; i < n; ++i) {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) ++k;
            d2[i] = k;
            if (i + k - 1 > r) l = i - k, r = i + k - 1;
        }
        return d2;
    }

public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if (n == 0 || k > n) return 0;

        vector<int> odd = oddPalindromes(s);
        vector<int> even = evenPalindromes(s);
        vector<int> dp(n + 1, 0);

        for (int r = 0; r < n; ++r) {
            dp[r + 1] = dp[r];
            for (int l = 0; l <= r; ++l) {
                int len = r - l + 1;
                bool palindrome;
                if (len & 1) {
                    int center = (l + r) / 2;
                    palindrome = odd[center] >= len / 2 + 1;
                } else {
                    int center = (l + r + 1) / 2;
                    palindrome = even[center] >= len / 2;
                }
                if (len >= k && palindrome)
                    dp[r + 1] = max(dp[r + 1], dp[l] + 1);
            }
        }
        return dp[n];
    }
};
