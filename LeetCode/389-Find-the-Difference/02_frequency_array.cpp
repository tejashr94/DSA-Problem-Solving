#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int freq[26] = {};

        for (char c : s) freq[c - 'a']++;
        for (char c : t) freq[c - 'a']--;

        for (int i = 0; i < 26; ++i) {
            if (freq[i] < 0) return char('a' + i);
        }

        return '\0';
    }
};
