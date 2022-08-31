//
// Created by adeshchoudhar on 29/8/22.
//

class Solution {
public:
    int numIslands(vector <vector<char>> &grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    ans += 1;
                    numIslandsUtil(grid, i, j);
                }
            }
        }
        return ans;
    }

    void numIslandsUtil(vector <vector<char>> &grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if ((i < 0) || (i >= m) || (j < 0) || (j >= n) || (grid[i][j] == '0')) {
            return;
        }
        grid[i][j] = '0';
        numIslandsUtil(grid, i, j - 1);
        numIslandsUtil(grid, i - 1, j);
        numIslandsUtil(grid, i, j + 1);
        numIslandsUtil(grid, i + 1, j);
    }
};
