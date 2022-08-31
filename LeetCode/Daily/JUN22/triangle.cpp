//
// Created by adeshchoudhar on 13/06/22.
//

class Solution {
public:
    int minimumTotal(vector <vector<int>> &triangle) {
        int ans;
        vector<int> dp(triangle.back());
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }
        ans = dp[0];
        return ans;
    }
};
