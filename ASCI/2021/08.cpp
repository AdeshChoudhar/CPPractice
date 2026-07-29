//
// Problem: Kadane's Algorithm
//

#include "../../utils/utils.h"

int solve(vector<int> &arr) {
  int ans = 0;

  int mxm = 0;
  for (int x : arr) {
    mxm = mxm + x;
    ans = max(ans, mxm);
    mxm = max(0, mxm);
  }

  return ans;
}

int main() {
  vector<int> arr = {2, 3, -8, 7, -1, 2, 3};

  cout << "INPUT(s):" << endl;
  printVector(arr, "  arr = ");

  int ans = solve(arr);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << ans << endl;

  return 0;
}
