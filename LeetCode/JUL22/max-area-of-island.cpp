//
// Created by adeshchoudhar on 15/7/22.
//

class Solution {
public:
    vector <vector<bool>> vis;

    int maxAreaOfIsland(vector <vector<int>> &grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        vis.resize(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((grid[i][j] == 1) && !vis[i][j]) {
                    ans = max(ans, maxAreaOfIslandUtil(grid, i, j));
                }
            }
        }
        return ans;
    }

    int maxAreaOfIslandUtil(vector <vector<int>> &grid, int i, int j) {
        int res = 0, m = grid.size(), n = grid[0].size();
        if ((i < 0) || (i >= m) || (j < 0) || (j >= n) ||
            (grid[i][j] == 0) || vis[i][j]) {
            return res;
        }
        vis[i][j] = true;
        res += (int) (grid[i][j] == 1) +
               maxAreaOfIslandUtil(grid, i, j - 1) +
               maxAreaOfIslandUtil(grid, i - 1, j) +
               maxAreaOfIslandUtil(grid, i, j + 1) +
               maxAreaOfIslandUtil(grid, i + 1, j);
        return res;
    }
};
