//
// Created by adeshchoudhar on 12/04/22.
//

class Solution {
public:
    void gameOfLife(vector <vector<int>> &board) {
        for (int i = 0, m = board.size(); i < m; i++) {
            for (int j = 0, n = board[0].size(); j < n; j++) {
                int cnt = -board[i][j];
                for (int x = max(i - 1, 0); x < min(i + 2, m); x++) {
                    for (int y = max(j - 1, 0); y < min(j + 2, n); y++) {
                        cnt += board[x][y] & 1;
                    }
                }
                if ((cnt | board[i][j]) == 3) {
                    board[i][j] |= 2;
                }
            }
        }
        for (int i = 0, m = board.size(); i < m; i++) {
            for (int j = 0, n = board[0].size(); j < n; j++) {
                board[i][j] >>= 1;
            }
        }
    }
};
