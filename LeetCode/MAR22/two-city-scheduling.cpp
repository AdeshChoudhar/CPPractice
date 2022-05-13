//
// Created by adeshchoudhar on 25/03/22.
//

class Solution {
public:
    int twoCitySchedCost(vector <vector<int>> &costs) {
        int ans = 0, n = costs.size() / 2;
        sort(costs.begin(), costs.end(), [](const vector<int> &a, const vector<int> &b) {
            return (a[0] - a[1]) < (b[0] - b[1]);
        });
        for (int i = 0; i < n; i++) {
            ans += (costs[i][0] + costs[i + n][1]);
        }
        return ans;
    }
};
