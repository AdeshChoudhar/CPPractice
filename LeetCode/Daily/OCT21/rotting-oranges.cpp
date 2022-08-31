//
// Created by adeshchoudhar on 29/10/21.
//

class Solution {
public:
    int orangesRotting(vector <vector<int>> &grid) {
        int row = grid.size(), col = grid[0].size();
        int fresh_oranges_count = 0;
        queue <pair<int, int>> rotten_oranges;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    fresh_oranges_count += 1;
                } else if (grid[i][j] == 2) {
                    rotten_oranges.push(make_pair(i, j));
                }
            }
        }

        int minutes = 0;
        vector <pair<int, int>> directions = {{1,  0},
                                              {-1, 0},
                                              {0,  1},
                                              {0,  -1}};
        while (!rotten_oranges.empty() and fresh_oranges_count) {
            minutes += 1;
            for (int i = 0, n = rotten_oranges.size(); i < n; i++) {
                pair<int, int> xy = rotten_oranges.front();
                rotten_oranges.pop();
                for (int j = 0; j < directions.size(); j++) {
                    int x = xy.first + directions[j].first;
                    int y = xy.second + directions[j].second;
                    if ((x >= 0) and (x <= (row - 1)) and (y >= 0) and (y <= (col - 1)) and (grid[x][y] == 1)) {
                        grid[x][y] = 2;
                        fresh_oranges_count -= 1;
                        rotten_oranges.push(make_pair(x, y));
                    }
                }
            }
        }

        return fresh_oranges_count ? -1 : minutes;
    }
};
