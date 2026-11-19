// LeetCode 30: Substring with Concatenation of All Words
// https://leetcode.com/problems/substring-with-concatenation-of-all-words/

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty() || words[0].empty()) return ans;

        int wordLen = words[0].size();
        int totalWords = words.size();
        int windowLen = wordLen * totalWords;
        if (s.size() < windowLen) return ans;

        unordered_map<string, int> need;
        for (const string& word : words) ++need[word];

        for (int offset = 0; offset < wordLen; ++offset) {
            unordered_map<string, int> seen;
            int left = offset, count = 0;

            for (int right = offset; right + wordLen <= (int)s.size(); right += wordLen) {
                string word = s.substr(right, wordLen);
                if (!need.count(word)) {
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                    continue;
                }

                ++seen[word];
                ++count;
                while (seen[word] > need[word]) {
                    string first = s.substr(left, wordLen);
                    --seen[first];
                    --count;
                    left += wordLen;
                }

                if (count == totalWords) {
                    ans.push_back(left);
                    string first = s.substr(left, wordLen);
                    --seen[first];
                    --count;
                    left += wordLen;
                }
            }
        }
        return ans;
    }
};