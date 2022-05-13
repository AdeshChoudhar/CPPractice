//
// Created by adeshchoudhar on 13/04/22.
//

class Solution {
public:
    vector <vector<int>> generateMatrix(int n) {
        vector <vector<int>> ans(n, vector<int>(n, 0));
        int i = 0, j = 0, di = 0, dj = 1, tmp;
        for (int x = 1, k = n * n; x <= k; x++) {
            ans[i][j] = x;
            if (ans[max(i + di, 0) % n][max(j + dj, 0) % n] != 0) {
                tmp = di;
                di = dj;
                dj = -1 * tmp;
            }
            i += di;
            j += dj;
        }
        return ans;
    }
};
