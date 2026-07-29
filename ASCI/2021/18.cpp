//
// Problem: Count pairs with given sum
//

#include "../../utils/utils.h"

int solve(vector<int> &arr, int target) {
  int ans = 0;

  unordered_map<int, int> um;

  for (int i = 0, n = arr.size(); i < n; i++) {
    ans += um[target - arr[i]];
    um[arr[i]] += 1;
  }

  return ans;
}

int main() {
  vector<int> arr = {1, 5, 7, -1, 5};
  int target = 6;

  cout << "INPUT(s):" << endl;
  printVector(arr, "  arr = ");
  cout << "  target = " << target << endl;

  int ans = solve(arr, target);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << ans << endl;

  return 0;
}
