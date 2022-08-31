//
// Created by adeshchoudhar on 18/7/22.
//

class Solution {
public:
    int numSubmatrixSumTarget(vector <vector<int>> &matrix, int target) {
        int ans = 0, m = matrix.size(), n = matrix[0].size(), sum;
        vector <vector<int>> dp(matrix.begin(), matrix.end());
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] += dp[i][j - 1];
            }
        }
        unordered_map<int, int> um;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                um.clear();
                um[0] = 1;
                sum = 0;
                for (int k = 0; k < m; k++) {
                    sum += dp[k][j] - ((i > 0) ? dp[k][i - 1] : 0);
                    ans += um[sum - target];
                    um[sum] += 1;
                }
            }
        }
        return ans;
    }
};
