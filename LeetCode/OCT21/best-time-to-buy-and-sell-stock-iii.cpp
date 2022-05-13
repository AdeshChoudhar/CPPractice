//
// Created by adeshchoudhar on 16/10/21.
//

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<int> left(n + 1, 0), right(n + 1, 0);

        int mini = 100001;
        for (int i = 0; i < n; i++) {
            left[i + 1] = max(left[i], prices[i] - mini);
            mini = min(mini, prices[i]);
        }

        int maxi = -1;
        for (int i = n - 1; i >= 0; i--) {
            right[i + 1] = max(right[i], maxi - prices[i]);
            maxi = max(maxi, prices[i]);
        }

        int ans = INT_MIN;
        for (int i = 0; i < n + 1; i++) {
            ans = max(ans, left[i] + right[i]);
        }
        return ans;
    }
};
