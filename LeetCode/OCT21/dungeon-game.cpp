//
// Created by adeshchoudhar on 02/10/21.
//

class Solution {
public:
    int calculateMinimumHP(vector <vector<int>> &dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector <vector<int>> dp(m, vector<int>(n, 0));
        for (int i = m - 1; i > -1; i--) {
            for (int j = n - 1; j > -1; j--) {
                if ((i == (m - 1)) && (j == (n - 1))) {
                    dp[i][j] = max(1, 1 - dungeon[i][j]);
                } else if (i == (m - 1)) {
                    dp[i][j] = max(1, (dp[i][j + 1] - dungeon[i][j]));
                } else if (j == (n - 1)) {
                    dp[i][j] = max(1, (dp[i + 1][j] - dungeon[i][j]));
                } else {
                    dp[i][j] = min(max(1, (dp[i + 1][j] - dungeon[i][j])),
                                   max(1, (dp[i][j + 1] - dungeon[i][j])));
                }
            }
        }

        int ans = dp[0][0];
        return ans;
    }
};
