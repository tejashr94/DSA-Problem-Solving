/**
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int start = 1, end = n;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            switch (guess(mid)) {
                case 0:
                    return mid;
                case -1:
                    end = mid - 1;
                    break;
                case 1:
                    start = mid + 1;
                    break;
            }
        }

        return -1;
    }
};
