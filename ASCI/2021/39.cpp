//
// Problem: Median in a Row-Wise Sorted Matrix
//

#include "../../utils/utils.h"

int solve(vector<vector<int>> &mat) {
  int ans;

  vector<int> v;

  int r = mat.size(), c = mat[0].size();
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      v.push_back(mat[i][j]);
    }
  }

  sort(v.begin(), v.end());

  int n = v.size();
  if ((n & 1) != 0) {
    ans = v[n / 2];
  } else {
    ans = (v[(n / 2) - 1] + v[n / 2]) / 2;
  }

  return ans;
}

int main() {
  vector<vector<int>> mat = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};

  cout << "INPUT(s):" << endl;
  printMatrix(mat, "  mat = ");

  int ans = solve(mat);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << ans << endl;

  return 0;
}
