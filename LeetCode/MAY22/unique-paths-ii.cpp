//
// Created by adeshchoudhar on 20/05/22.
//

class Solution {
public:
    int uniquePathsWithObstacles(vector <vector<int>> &obstacleGrid) {
        int ans = 0, m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if ((obstacleGrid[0][0] == 1) || (obstacleGrid[m - 1][n - 1] == 1)) {
            return ans;
        }
        obstacleGrid[0][0] = 1;
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 0) {
                obstacleGrid[i][0] = obstacleGrid[i - 1][0];
            } else {
                obstacleGrid[i][0] = 0;
            }
        }
        for (int i = 1; i < n; i++) {
            if (obstacleGrid[0][i] == 0) {
                obstacleGrid[0][i] = obstacleGrid[0][i - 1];
            } else {
                obstacleGrid[0][i] = 0;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
                } else {
                    obstacleGrid[i][j] = 0;
                }
            }
        }
        ans = obstacleGrid[m - 1][n - 1];
        return ans;
    }
};
