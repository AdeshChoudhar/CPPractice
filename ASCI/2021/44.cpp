//
// Problem: Rotate Matrix Clockwise by One
//

#include "../../utils/utils.h"

vector<vector<int>> solve(vector<vector<int>> &mat) {
  vector<vector<int>> ans = mat;

  int t = 0, b = ans.size() - 1, l = 0, r = ans[0].size() - 1;

  while ((t < b) && (l < r)) {
    int tmp = ans[t][l];

    for (int i = t; i < b; i++) {
      ans[i][l] = ans[i + 1][l];
    }

    for (int i = l; i < r; i++) {
      ans[b][i] = ans[b][i + 1];
    }

    for (int i = b; i > t; i--) {
      ans[i][r] = ans[i - 1][r];
    }

    for (int i = r; i > l; i--) {
      ans[t][i] = ans[t][i - 1];
    }

    ans[t][l + 1] = tmp;

    t += 1;
    b -= 1;
    l += 1;
    r -= 1;
  }

  return ans;
}

int main() {
  vector<vector<int>> mat = {{1, 2, 3}, {2, 3, 3}};

  cout << "INPUT(s):" << endl;
  printMatrix(mat, "mat = ");

  vector<vector<int>> ans = solve(mat);

  cout << "OUTPUT(s):" << endl;
  printMatrix(ans, "ans = ");

  return 0;
}
