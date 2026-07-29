//
// Problem: Max Diff with Below and Right in Grid
//

#include "../../utils/utils.h"

int solve(vector<vector<int>> &mat) {
  int ans = INT_MIN;

  int n = mat.size(), mxm;

  vector<vector<int>> res(n, vector<int>(n));
  res[n - 1][n - 1] = mat[n - 1][n - 1];

  mxm = mat[n - 1][n - 1];
  for (int i = n - 2; i >= 0; i--) {
    mxm = max(mxm, mat[n - 1][i]);
    res[n - 1][i] = mxm;
  }

  mxm = mat[n - 1][n - 1];
  for (int i = n - 2; i >= 0; i--) {
    mxm = max(mxm, mat[i][n - 1]);
    res[i][n - 1] = mxm;
  }

  for (int i = n - 2; i >= 0; i--) {
    for (int j = n - 2; j >= 0; j--) {
      ans = max(ans, (res[i + 1][j + 1] - mat[i][j]));
      res[i][j] = max(mat[i][j], max(res[i][j + 1], res[i + 1][j]));
    }
  }

  return ans;
}

int main() {
  vector<vector<int>> mat = {{1, 2, -1, -4, -20},
                             {-8, -3, 4, 2, 1},
                             {3, 8, 6, 1, 3},
                             {-4, -1, 1, 7, -6},
                             {0, -4, 10, -5, 1}};

  cout << "INPUT(s):" << endl;
  printMatrix(mat, "  mat = ");

  int ans = solve(mat);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << ans << endl;

  return 0;
}
