//
// Problem: Max rectangle
//

#include "../../utils/utils.h"

int maxAreaUtil(vector<int> &v) {
  int res = 0;

  stack<int> s;

  int i = 0, n = v.size(), top, mxm;
  while (i < n) {
    if (s.empty() || (v[s.top()] <= v[i])) {
      s.push(i);
      i += 1;
    } else {
      top = s.top();
      s.pop();
      mxm = v[top] * (s.empty() ? i : i - s.top() - 1);
      res = max(res, mxm);
    }
  }

  while (s.empty() == false) {
    top = s.top();
    s.pop();
    mxm = v[top] * (s.empty() ? i : i - s.top() - 1);
    res = max(res, mxm);
  }

  return res;
}

int solve(vector<vector<int>> &mat) {
  int ans = 0;

  int mxm = 0;
  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[0].size(); j++) {
      if ((i != 0) && (mat[i][j] != 0)) {
        mat[i][j] += mat[i - 1][j];
      }
    }

    mxm = maxAreaUtil(mat[i]);
    ans = max(ans, mxm);
  }

  return ans;
}

int main() {
  vector<vector<int>> mat = {
      {0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};

  cout << "INPUT(s):" << endl;
  printMatrix(mat, "  mat = ");

  int ans = solve(mat);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << ans << endl;

  return 0;
}
