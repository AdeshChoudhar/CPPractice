//
// Problem: Sort a Matrix
//

#include "../../utils/utils.h"

vector<vector<int>> solve(vector<vector<int>> mat) {
  vector<vector<int>> ans;

  vector<int> res;
  int n = mat.size();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      res.push_back(mat[i][j]);
    }
  }

  sort(res.begin(), res.end());

  for (int i = 0; i < n; i++) {
    vector<int> v;

    for (int j = 0; j < n; j++) {
      v.push_back(res[i * n + j]);
    }

    ans.push_back(v);
  }

  return ans;
}

int main() {
  vector<vector<int>> mat = {
      {10, 20, 30, 40}, {15, 25, 35, 45}, {27, 29, 37, 48}, {32, 33, 39, 50}};

  cout << "INPUT(s):" << endl;
  printMatrix(mat, "  mat = ");

  vector<vector<int>> ans = solve(mat);

  cout << "OUTPUT(s):" << endl;
  printMatrix(ans, "  ans = ");

  return 0;
}
