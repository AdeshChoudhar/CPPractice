//
// Problem: Trapping Rain Water
//

#include "../../utils/utils.h"

int solve(vector<int> &arr) {
  int ans = 0;

  int n = arr.size();
  vector<int> left(n), right(n);

  left[0] = arr[0];
  for (int i = 1; i < n; i++) {
    left[i] = max(left[i - 1], arr[i]);
  }

  right[n - 1] = arr[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    right[i] = max(right[i + 1], arr[i]);
  }

  for (int i = 0; i < n; i++) {
    ans += min(left[i], right[i]) - arr[i];
  }

  return ans;
}

int main() {
  vector<int> arr = {3, 0, 1, 0, 4, 0, 2};

  cout << "INPUT(s):" << endl;
  printVector(arr, "  arr = ");

  int ans = solve(arr);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << ans << endl;

  return 0;
}
