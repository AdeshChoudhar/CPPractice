//
// Problem: Kth smallest element in a Matrix
//

#include "../../utils/utils.h"

int kSmallestUtil(vector<vector<int>> &mat, int mid) {
  int res = 0;

  for (int i = 0, n = mat.size(); i < n; i++) {
    if (mat[i][0] > mid) {
      return res;
    }

    if (mat[i][n - 1] <= mid) {
      res += n;
      continue;
    }

    res += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
  }

  return res;
}

int solve(vector<vector<int>> &mat, int k) {
  int ans;

  int n = mat.size(), l = mat[0][0], r = mat[n - 1][n - 1];
  while (l <= r) {
    int mid = l + (r - l) / 2;
    int res = kSmallestUtil(mat, mid);
    if (res >= k) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  ans = l;

  return ans;
}

int main() {
  vector<vector<int>> mat = {
      {16, 28, 60, 64}, {22, 41, 63, 91}, {27, 50, 87, 93}, {36, 78, 87, 94}};
  int k = 3;

  cout << "INPUT(s):" << endl;
  printMatrix(mat, "mat = ");
  cout << "  k = " << k << endl;

  int ans = solve(mat, k);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << ans << endl;

  return 0;
}
