//
// Created by adeshchoudhar on 30/05/22.
//

class Solution {
public:
    int divide(int dividend, int divisor) {
        int ans = 0;
        if (divisor == 1) {
            ans = dividend;
            return ans;
        }
        if (dividend == divisor) {
            ans = 1;
            return ans;
        }
        if ((dividend == INT_MIN) && (divisor == -1)) {
            ans = INT_MAX;
            return ans;
        }
        bool sign = ((dividend > 0) == (divisor > 0));
        long a = abs((long) dividend), b = abs((long) divisor), t, p;
        while (a >= b) {
            t = b;
            p = 1;
            while (a > (t << 1)) {
                p <<= 1;
                t <<= 1;
            }
            ans += p;
            a -= t;
        }
        ans = sign ? ans : -ans;
        return ans;
    }
};
