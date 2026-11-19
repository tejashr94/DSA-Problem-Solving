// LeetCode 28: Find the Index of the First Occurrence in a String
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        size_t pos = haystack.find(needle);
        return pos == string::npos ? -1 : (int)pos;
    }
};