//
// Created by adeshchoudhar on 11/12/21.
//

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        int ans = 0;
        long long mod = (int) (1e9 + 7);
        long long lcm = (a * b) / __gcd(a, b);
        long long tmp = (lcm / a) + (lcm / b) - 1;
        long long k = (n - 1) / tmp;
        for (int i = 1, j = 1, required = n - tmp * k; required; required--) {
            if (a * i < b * j) {
                ans = (a * i) % mod;
                i += 1;
            } else {
                ans = (b * j) % mod;
                j += 1;
            }
        }
        ans = (lcm * k + ans) % mod;
        return ans;
    }
};
