//
// Created by adeshchoudhar on 10/9/22.
//

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int ans, n = prices.size();
        if (k >= (n / 2)) {
            ans = 0;
            for (int i = 1; i < n; i++) {
                ans += max(0, prices[i] - prices[i - 1]);
            }
        } else {
            vector<int> b(k + 1, INT_MIN), s(k + 1, 0);
            for (int x: prices) {
                for (int i = 1; i <= k; i++) {
                    b[i] = max(b[i], s[i - 1] - x);
                    s[i] = max(s[i], b[i] + x);
                }
            }
            ans = s[k];
        }
        return ans;
    }
};
