//
// Problem: Find unique element
//

#include "../../utils/utils.h"

int solve(vector<int> &arr, int k) {
  int ans;

  unordered_map<int, int> um;
  for (int x : arr) {
    um[x] += 1;
  }

  for (auto x : um) {
    if ((x.second % k) != 0) {
      ans = x.first;
      break;
    }
  }

  return ans;
}

int main() {
  vector<int> arr = {6, 2, 5, 2, 2, 6, 6};
  int k = 3;

  cout << "INPUT(s):" << endl;
  printVector(arr, "  arr = ");
  cout << "  k = " << k << endl;

  int ans = solve(arr, k);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << ans << endl;

  return 0;
}
