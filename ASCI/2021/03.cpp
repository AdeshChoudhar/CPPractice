//
// Problem: Kth Smallest
//

#include "../../utils/utils.h"

int solve(vector<int> &v, int k) {
  int ans;

  sort(v.begin(), v.end());

  ans = v[k - 1];

  return ans;
}

int main() {
  vector<int> v = {10, 5, 4, 3, 48, 6, 2, 33, 53, 10};
  int k = 4;

  cout << "INPUT(s):" << endl;
  printVector(v, "  v = ");
  cout << "  k = " << k << endl;

  int ans = solve(v, k);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << ans << endl;

  return 0;
}
