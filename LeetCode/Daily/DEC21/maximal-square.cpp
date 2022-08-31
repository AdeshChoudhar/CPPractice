//
// Created by adeshchoudhar on 17/12/21.
//

class Solution {
public:
    int maximalSquare(vector <vector<char>> &matrix) {
        int row = matrix.size(), col = matrix[0].size(), side = 0;
        for (int r = row - 1; r >= 0; r--) {
            for (int c = col - 1; c >= 0; c--) {
                if ((r == (row - 1)) || (c == (col - 1))) {
                    side = max(side, (int) (matrix[r][c] -= '0'));
                } else {
                    if (matrix[r][c] == '1') {
                        matrix[r][c] = 1 + min({matrix[r + 1][c], matrix[r][c + 1], matrix[r + 1][c + 1]});
                    } else {
                        matrix[r][c] = 0;
                    }
                    side = max(side, (int) (matrix[r][c]));
                }
            }
        }
        int ans = side * side;
        return ans;
    }
};
