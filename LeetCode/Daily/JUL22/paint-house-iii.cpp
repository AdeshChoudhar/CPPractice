//
// Created by adeshchoudhar on 8/7/22.
//

class Solution {
public:
    int dp[101][101][21];

    int minCost(vector<int> &houses, vector <vector<int>> &cost, int m, int n, int target) {
        int ans;
        memset(dp, 0, 101 * 101 * 21);
        ans = minCostUtil(houses, cost, 0, target, 0);
        ans = (ans > 1e9) ? -1 : ans;
        return ans;
    }

    int minCostUtil(vector<int> &houses, vector <vector<int>> &cost, int i, int t, int c) {
        int res = 1e9 + 1;
        if ((i >= houses.size()) || (t < 0)) {
            res = (t == 0) ? 0 : res;
        } else if (houses[i] != 0) {
            res = minCostUtil(houses, cost, i + 1, t - (c != houses[i]), houses[i]);
        } else if (dp[i][t][c] != 0) {
            res = dp[i][t][c];
        } else {
            for (int j = 1; j <= cost[i].size(); j++) {
                res = min(res, cost[i][j - 1] + minCostUtil(houses, cost, i + 1, t - (c != j), j));
            }
            dp[i][t][c] = res;
        }
        return res;
    }
};
