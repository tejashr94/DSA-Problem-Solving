// LeetCode 6: Zigzag Conversion
// Approach: Simulation
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= static_cast<int>(s.size())) {
            return s;
        }

        vector<string> rows(numRows);
        int currentRow = 0;
        int direction = -1;

        for (char c : s) {
            rows[currentRow] += c;

            if (currentRow == 0 || currentRow == numRows - 1) {
                direction *= -1;
            }

            currentRow += direction;
        }

        string result;
        for (const string& row : rows) {
            result += row;
        }

        return result;
    }
};
