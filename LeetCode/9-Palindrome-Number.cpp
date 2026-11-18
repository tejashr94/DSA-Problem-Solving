// LeetCode 9: Palindrome Number
// https://leetcode.com/problems/palindrome-number/

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // For odd-length numbers, ignore the middle digit.
        return x == reversedHalf || x == reversedHalf / 10;
    }
};
