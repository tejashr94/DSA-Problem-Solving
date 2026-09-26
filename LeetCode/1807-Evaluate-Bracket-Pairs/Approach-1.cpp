class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '(') {
                ans += s[i];
                continue;
            }
            int j = i + 1;
            while (s[j] != ')') j++;
            ans += s.substr(i + 1, j - i - 1);
            i = j;
        }
        return ans;
    }
};