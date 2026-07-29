//
// Problem: More than n/k Occurrences
//

#include "../../utils/utils.h"

int solve(vector<int> &arr, int k) {
  int ans = 0;

  int n = arr.size();
  unordered_map<int, int> um;

  for (int i = 0; i < n; i++) {
    um[arr[i]] += 1;
  }

  int cnt = n / k;
  for (auto x : um) {
    ans += (int)(x.second > cnt);
  }

  return ans;
}

int main() {
  vector<int> arr = {3, 1, 2, 2, 1, 2, 3, 3};
  int k = 4;

  cout << "INPUT(s):" << endl;
  printVector(arr, "  arr = ");
  cout << "  k = " << k << endl;

  int ans = solve(arr, k);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << ans << endl;

  return 0;
}
