//
// Problem: Search in a Row-Column Sorted
//

#include "../../utils/utils.h"

bool solve(vector<vector<int>> &mat, int x) {
  bool ans = false;

  int r = mat.size(), c = mat[0].size(), i = 0, j = c - 1;
  while ((i >= 0) && (i < r) && (j >= 0) && (j < c)) {
    if (mat[i][j] < x) {
      i += 1;
    } else if (mat[i][j] > x) {
      j -= 1;
    } else {
      ans = true;
      return ans;
    }
  }

  return ans;
}
int main() {
  vector<vector<int>> mat = {{3, 30, 38}, {20, 52, 54}, {35, 60, 69}};
  int x = 62;

  cout << "INPUT(s):" << endl;
  printMatrix(mat, "  mat = ");
  cout << "  x = " << x << endl;

  bool ans = solve(mat, x);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << (ans ? "true" : "false") << endl;

  return 0;
}
