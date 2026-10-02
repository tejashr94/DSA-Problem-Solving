/**
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (guess(mid) > 0)
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }
};
