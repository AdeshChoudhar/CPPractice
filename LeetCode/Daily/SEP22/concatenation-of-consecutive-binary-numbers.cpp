//
// Created by adeshchoudhar on 23/9/22.
//

class Solution {
public:
    int concatenatedBinary(int n) {
        int ans, mod = (int) (1e9 + 7);
        long long res = 0;
        for (int i = 1; i <= n; i++) {
            int len = log2(i) + 1;
            res = ((res << len) % mod + i) % mod;
        }
        ans = res % mod;
        return ans;
    }
};
