//
// Created by adeshchoudhar on 16/05/22.
//

class Solution {
public:
    vector <pair<int, int>> dir = {{1,  1},
                                   {0,  1},
                                   {1,  0},
                                   {0,  -1},
                                   {-1, 0},
                                   {-1, -1},
                                   {1,  -1},
                                   {-1, 1}};

    int shortestPathBinaryMatrix(vector <vector<int>> &grid) {
        int ans = -1, n = grid.size(), x, y, X, Y;
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return ans;
        }
        queue <pair<int, int>> q;
        q.push(make_pair(0, 0));
        grid[0][0] = 1;
        while (!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            if ((x == n - 1) && (y == n - 1)) {
                ans = grid[x][y];
                break;
            }
            for (auto d: dir) {
                X = x + d.first;
                Y = y + d.second;
                if ((X >= 0) && (X < n) && (Y >= 0) && (Y < n) && (grid[X][Y] == 0)) {
                    q.push(make_pair(X, Y));
                    grid[X][Y] = grid[x][y] + 1;
                }
            }
            q.pop();
        }
        return ans;
    }
};
