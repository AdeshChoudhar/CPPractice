//
// Problem: Minimize the Heights II
//

#include "../../utils/utils.h"

int solve(vector<int> &arr, int k) {
  int ans;

  sort(arr.begin(), arr.end());

  ans = arr.back() - arr.front();

  int l = arr.front() + k, r = arr.back() - k;
  for (int i = 0, n = arr.size(); i < (n - 1); i++) {
    int mnm = min(l, arr[i + 1] - k);
    int mxm = max(r, arr[i] + k);
    if (mnm >= 0) {
      ans = min(ans, mxm - mnm);
    }
  }

  return ans;
}

int main() {
  vector<int> arr = {1, 5, 8, 10};
  int k = 2;

  cout << "INPUT(s):" << endl;
  printVector(arr, "  arr = ");
  cout << "  k = " << k << endl;

  int ans = solve(arr, k);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << ans << endl;

  return 0;
}
