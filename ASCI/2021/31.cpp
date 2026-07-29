//
// Problem: Smallest subarray with sum greater than x
//

#include "../../utils/utils.h"

int solve(vector<int> &arr, int x) {
  int ans = INT_MAX;

  int n = arr.size(), sum = 0, i = 0;
  for (int j = 0; j < n; j++) {
    sum += arr[j];
    while (sum > x) {
      ans = min(ans, j - i + 1);
      sum -= arr[i];
      i += 1;
    }
  }

  ans = (ans == INT_MAX) ? 0 : ans;

  return ans;
}

int main() {
  vector<int> arr = {1, 4, 45, 6, 0, 19};
  int x = 51;

  cout << "INPUT(s):" << endl;
  printVector(arr, "  arr = ");

  int ans = solve(arr, x);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << ans << endl;

  return 0;
}
