//
// Problem: Stock buy and sell
//

#include "../../utils/utils.h"

int solve(vector<int> &arr) {
  int ans = 0;

  for (int i = 0, n = arr.size(); i < (n - 1); i++) {
    if (arr[i] < arr[i + 1]) {
      ans += (arr[i + 1] - arr[i]);
    }
  }

  return ans;
}

int main() {
  vector<int> arr = {100, 180, 260, 310, 40, 535, 695};

  cout << "INPUT(s):" << endl;
  printVector(arr, "  arr = ");

  int ans = solve(arr);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << ans << endl;

  return 0;
}
