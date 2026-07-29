//
// Problem: Common in Rows of a Matrix
//

#include "../../utils/utils.h"

int solve(vector<vector<int>> &mat) {
  int ans = 0;

  int m = mat.size(), n = mat[0].size();

  unordered_map<int, int> mp;
  for (int i = 0; i < n; i++) {
    mp[mat[0][i]] = 1;
  }

  for (int i = 1; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (mp[mat[i][j]] == i) {
        mp[mat[i][j]] += 1;
      }
    }
  }

  for (auto x : mp) {
    ans += (int)(x.second == m);
  }

  return ans;
}

int main() {
  vector<vector<int>> mat = {
      {2, 1, 4, 3}, {1, 2, 3, 2}, {3, 6, 2, 3}, {5, 2, 5, 3}};

  cout << "INPUT(s):" << endl;
  printMatrix(mat, "mat = ");

  int ans = solve(mat);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << ans << endl;

  return 0;
}
