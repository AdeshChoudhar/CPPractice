//
// Problem: Minimum Swaps to Group Elements <= K
//

#include "../../utils/utils.h"

int solve(vector<int> &arr, int k) {
  int ans;

  int cnt = 0, n = arr.size();
  for (int i = 0; i < n; i++) {
    if (arr[i] <= k) {
      cnt += 1;
    }
  }

  int len = 0;
  for (int i = 0; i < cnt; i++) {
    if (arr[i] > k) {
      len += 1;
    }
  }

  ans = len;
  for (int i = 0, j = cnt; j < n; i++, j++) {
    if (arr[i] > k) {
      len -= 1;
    }

    if (arr[j] > k) {
      len += 1;
    }

    ans = min(ans, len);
  }

  return ans;
}

int main() {
  vector<int> arr = {2, 1, 5, 6, 3};
  int k = 3;

  cout << "INPUT(s):" << endl;
  printVector(arr, "  arr = ");
  cout << "  k = " << k << endl;

  int ans = solve(arr, k);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << ans << endl;

  return 0;
}
