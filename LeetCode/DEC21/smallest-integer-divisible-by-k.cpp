//
// Created by adeshchoudhar on 30/12/21.
//

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int ans = -1;
        if ((k % 2 == 0) || (k % 5 == 0)) {
            return ans;
        }
        for (int i = 1, r = 0; i <= k; i++) {
            r = (r * 10 + 1) % k;
            if (r == 0) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
