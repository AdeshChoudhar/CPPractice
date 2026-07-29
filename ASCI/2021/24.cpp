//
// Problem: Longest Consecutive Subsequence
//

#include "../../utils/utils.h"

int solve(vector<int> &arr) {
  int ans = 1;

  set<int> s(arr.begin(), arr.end());
  vector<int> v(s.begin(), s.end());

  sort(v.begin(), v.end());

  int cnt = 1;
  for (int i = 1, n = v.size(); i < n; i++) {
    if ((v[i] - v[i - 1]) == 1) {
      cnt += 1;
    } else {
      cnt = 1;
    }

    ans = max(ans, cnt);
  }

  return ans;
}

int main() {
  vector<int> arr = {2, 6, 1, 9, 4, 5, 3};

  cout << "INPUT(s):" << endl;
  printVector(arr, "  arr = ");

  int ans = solve(arr);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << ans << endl;

  return 0;
}
