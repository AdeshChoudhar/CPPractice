//
// Created by adeshchoudhar on 02/11/21.
//

class Solution {
public:
    int uniquePathsIII(vector <vector<int>> &grid) {
        int x = 0, y = 0, zeroes = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    zeroes += 1;
                } else if (grid[i][j] == 1) {
                    x = i;
                    y = j;
                }
            }
        }
        int ans = dfs(grid, x, y, zeroes);
        return ans;
    }

    int dfs(vector <vector<int>> &grid, int x, int y, int zeroes) {
        if (x < 0 || x > (grid.size() - 1) || y < 0 || y > (grid[0].size() - 1) || grid[x][y] == -1) {
            return 0;
        }

        if (grid[x][y] == 2) {
            return (zeroes == -1) ? 1 : 0;
        }

        grid[x][y] = -1;
        zeroes -= 1;

        int total_paths = dfs(grid, x + 1, y, zeroes) +
                          dfs(grid, x - 1, y, zeroes) +
                          dfs(grid, x, y + 1, zeroes) +
                          dfs(grid, x, y - 1, zeroes);

        grid[x][y] = 0;
        zeroes += 1;

        return total_paths;
    }
};
