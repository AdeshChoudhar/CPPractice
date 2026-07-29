//
// Problem: Chocolate Distribution Problem
//

#include "../../utils/utils.h"

int solve(vector<int> &a, int m) {
  int ans = INT_MAX;

  sort(a.begin(), a.end());

  for (int i = 0, n = a.size(); i < (n - (m - 1)); i++) {
    ans = min(ans, a[i + m - 1] - a[i]);
  }

  return ans;
}
int main() {
  vector<int> a = {3, 4, 1, 9, 56, 7, 9, 12};
  int m = 5;

  cout << "INPUT(s):" << endl;
  printVector(a, "  a = ");
  cout << "  m = " << m << endl;

  int ans = solve(a, m);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << ans << endl;

  return 0;
}
