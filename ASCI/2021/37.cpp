//
// Problem: Spirally Traversing a Matrix
//

#include "../../utils/utils.h"

vector<int> solve(vector<vector<int>> &mat) {
  vector<int> ans;

  int row = mat.size(), col = mat[0].size();
  ans.resize(row * col);

  int r = 0, c = 0, idx = 0;
  while ((r < row) && (c < col)) {
    for (int i = c; i < col; i++, idx++) {
      ans[idx] = mat[r][i];
    }

    r += 1;

    for (int i = r; i < row; i++, idx++) {
      ans[idx] = mat[i][col - 1];
    }

    col -= 1;

    if (r < row) {
      for (int i = col - 1; i >= c; --i, idx++) {
        ans[idx] = mat[row - 1][i];
      }

      row -= 1;
    }

    if (c < col) {
      for (int i = row - 1; i >= r; --i, idx++) {
        ans[idx] = mat[i][c];
      }

      c += 1;
    }
  }

  return ans;
}
int main() {
  vector<vector<int>> mat = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

  cout << "INPUT(s):" << endl;
  printMatrix(mat, "  mat = ");

  vector<int> ans = solve(mat);

  cout << "OUTPUT(s):" << endl;
  printVector(ans, "  ans = ");

  return 0;
}
