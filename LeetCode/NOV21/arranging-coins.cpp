//
// Created by adeshchoudhar on 05/11/21.
//

class Solution {
public:
    int arrangeCoins(int n) {
        int low = 0, high = n;
        while (low <= high) {
            long long int mid = low + (high - low) / 2;
            long long int tmp = (mid * (mid + 1)) / 2;
            if (tmp < (long long int) n) {
                low = mid + 1;
            } else if (tmp > (long long int) n) {
                high = mid - 1;
            } else {
                return mid;
            }
        }
        return high;
    }
};
