//
// Problem: Median of 2 Sorted Arrays of Different Sizes
//

#include "../../utils/utils.h"

double solve(vector<int> &a, vector<int> &b) {
  double ans = 0;

  int n1 = a.size(), n2 = b.size();
  if (n1 > n2) {
    ans = solve(b, a);
    return ans;
  }

  int n = n1 + n2;
  int mid = (n + 1) / 2;
  int low = 0, hih = n1;

  while (low <= hih) {
    int m1 = low + (hih - low) / 2;
    int m2 = mid - m1;

    int l1 = (m1 > 0) ? a[m1 - 1] : INT_MIN;
    int l2 = (m2 > 0) ? b[m2 - 1] : INT_MIN;
    int r1 = (m1 < n1) ? a[m1] : INT_MAX;
    int r2 = (m2 < n2) ? b[m2] : INT_MAX;

    if ((l1 <= r2) && (l2 <= r1)) {
      if ((n & 1) != 0) {
        ans = max(l1, l2);
      } else {
        ans = (max(l1, l2) + min(r1, r2)) / (double)2;
      }
      return ans;
    } else if (l1 > r2) {
      hih = m1 - 1;
    } else {
      low = m1 + 1;
    }
  }

  return ans;
}

int main() {
  vector<int> a = {3, 5, 6, 12, 15};
  vector<int> b = {3, 4, 6, 10, 10, 12};

  cout << "INPUT(s):" << endl;
  printVector(a, "  a = ");
  printVector(b, "  b = ");

  int ans = solve(a, b);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << ans << endl;

  return 0;
}
