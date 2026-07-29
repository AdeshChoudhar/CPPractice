//
// Problem: Minimum Jumps
//

#include "../../utils/utils.h"

int solve(vector<int> &arr) {
  int ans = 0;

  int s = 0, e = 0;
  for (int i = 0, n = arr.size(); i < (n - 1); i++) {
    e = max(e, arr[i] + i);
    if (i == s) {
      s = e;
      ans += 1;
      if (e >= (n - 1)) {
        break;
      }
    }
  }

  ans = (ans == 0) ? -1 : ans;

  return ans;
}

int main() {
  vector<int> arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};

  cout << "INPUT(s):" << endl;
  printVector(arr, "  arr = ");

  int ans = solve(arr);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << ans << endl;

  return 0;
}
