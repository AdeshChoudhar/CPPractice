//
// Created by adeshchoudhar on 12/10/21.
//

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;
        int mid = 1 + ((n - 1) / 2);
        while (low < high) {
            if (guess(mid) == -1) {
                high = mid - 1;
            } else if (guess(mid) == 1) {
                low = mid + 1;
            } else {
                break;
            }
            mid = low + ((high - low) / 2);
        }
        return mid;
    }
};
