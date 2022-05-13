//
// Created by adeshchoudhar on 30/11/21.
//

class Solution {
public:
    int maximalRectangle(vector <vector<char>> &matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> heights(col, 0), lefts(col, 0), rights(col, col);
        int ans = 0, current_left, current_right;
        for (int i = 0; i < row; i++) {
            current_left = 0;
            current_right = col;
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                    lefts[j] = max(lefts[j], current_left);
                } else {
                    heights[j] = 0;
                    lefts[j] = 0;
                    current_left = j + 1;
                }
                if (matrix[i][col - 1 - j] == '1') {
                    rights[col - 1 - j] = min(rights[col - 1 - j], current_right);
                } else {
                    rights[col - 1 - j] = col;
                    current_right = col - 1 - j;
                }
            }
            for (int j = 0; j < col; j++) {
                ans = max(ans, (rights[j] - lefts[j]) * heights[j]);
            }
        }
        return ans;
    }
};
