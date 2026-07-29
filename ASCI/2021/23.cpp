//
// Problem: Maximum Product Subarray
//

#include "../../utils/utils.h"

int solve(vector<int> &arr) {
  int ans = arr[0];

  int mnm = arr[0], mxm = arr[0];
  for (int i = 1, n = arr.size(); i < n; i++) {
    if (arr[i] < 0) {
      swap(mxm, mnm);
    }

    mnm = min(arr[i], mnm * arr[i]);
    mxm = max(arr[i], mxm * arr[i]);
    ans = max(ans, mxm);
  }

  return ans;
}

int main() {
  vector<int> arr = {-2, 6, -3, -10, 0, 2};

  cout << "INPUT(s):" << endl;
  printVector(arr, "  arr = ");

  int ans = solve(arr);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << ans << endl;

  return 0;
}
