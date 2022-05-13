//
// Created by adeshchoudhar on 01/02/22.
//

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ans = 0, mini = prices[0];
        for (int i = 1, n = prices.size(); i < n; i++) {
            ans = max(ans, prices[i] - mini);
            mini = min(mini, prices[i]);
        }
        return ans;
    }
};
