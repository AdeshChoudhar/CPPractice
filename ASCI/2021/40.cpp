//
// Problem: Row with Max 1s in Rowwise Sorted
//

#include "../../utils/utils.h"

int solve(vector<vector<int>> &arr) {
  int ans = -1;

  int mxm = -1, cnt = 0, r = arr.size(), c = arr[0].size();
  for (int i = 0; i < r; i++) {
    cnt = count(arr[i].begin(), arr[i].end(), 1);
    if (cnt > mxm) {
      mxm = cnt;
      ans = i;
    }
  }

  return ans;
}

int main() {
  vector<vector<int>> arr = {
      {0, 1, 1, 1}, {0, 0, 1, 1}, {1, 1, 1, 1}, {0, 0, 0, 0}};

  cout << "INPUT(s):" << endl;
  printMatrix(arr, "  arr = ");

  int ans = solve(arr);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << ans << endl;

  return 0;
}
