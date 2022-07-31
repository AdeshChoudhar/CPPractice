//
// Created by adeshchoudhar on 24/7/22.
//

class Solution {
public:
    bool searchMatrix(vector <vector<int>> &matrix, int target) {
        bool ans = false;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0, j = n - 1; !ans && (i < m) && (j >= 0);) {
            if (matrix[i][j] < target) {
                i += 1;
            } else if (matrix[i][j] > target) {
                j -= 1;
            } else {
                ans = true;
            }
        }
        return ans;
    }
};
