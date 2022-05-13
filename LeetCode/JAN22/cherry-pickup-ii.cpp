//
// Created by adeshchoudhar on 08/01/22.
//

class Solution {
public:
    int cherryPickup(vector <vector<int>> &grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector < vector < vector < int>>> dp(rows + 1, vector < vector < int >> (cols, vector<int>(cols, 0)));
        dp[0][0][cols - 1] = grid[0][0] + grid[0][cols - 1];
        for (int row = 1; row < rows; row++) {
            for (int col1 = 0; col1 < min(cols, row + 1); col1++) {
                for (int col2 = max(0, cols - 1 - row); col2 < cols; col2++) {
                    int previous = 0;
                    for (int i = max(0, col1 - 1); i <= min(cols - 1, col1 + 1); i++) {
                        for (int j = max(0, col2 - 1); j <= min(cols - 1, col2 + 1); j++) {
                            previous = max(previous, dp[row - 1][i][j]);
                        }
                    }
                    if (col1 == col2) {
                        dp[row][col1][col2] = previous + grid[row][col1];
                    } else {
                        dp[row][col1][col2] = previous + grid[row][col1] + grid[row][col2];
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < cols; j++) {
                ans = max(ans, dp[rows - 1][i][j]);
            }
        }
        return ans;
    }
};
