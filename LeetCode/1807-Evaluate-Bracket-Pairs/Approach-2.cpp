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

            string key = s.substr(i + 1, j - i - 1);
            string value = "?";

            for (auto &p : knowledge) {
                if (p[0] == key) {
                    value = p[1];
                    break;
                }
            }

            ans += value;
            i = j;
        }
        return ans;
    }
};