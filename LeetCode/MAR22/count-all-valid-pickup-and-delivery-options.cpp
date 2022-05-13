//
// Created by adeshchoudhar on 06/03/22.
//

class Solution {
public:
    int countOrders(int n) {
        int ans;
        long long res = 1, mod = 1000000007;
        for (int i = 1; i < n + 1; i++) {
            res = (res * i) % mod;
        }
        for (int i = 1; i < 2 * n; i += 2) {
            res = (res * i) % mod;
        }
        ans = res % mod;
        return ans;
    }
};
