//
// Created by adeshchoudhar on 4/8/22.
//

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int ans, gcd = __gcd(p, q), m = q / gcd, n = p / gcd;
        if (!(m & 1) && (n & 1)) {
            ans = 0;
        } else if ((m & 1) && (n & 1)) {
            ans = 1;
        } else if ((m & 1) && !(n & 1)) {
            ans = 2;
        }
        return ans;
    }
};
