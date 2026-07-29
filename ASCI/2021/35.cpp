//
// Problem: Median of an Array
//

#include "../../utils/utils.h"

double solve(vector<int> &arr) {
  double ans;

  sort(arr.begin(), arr.end());

  int n = arr.size();
  if ((n & 1) != 0) {
    ans = arr[n / 2];
  } else {
    ans = (arr[(n / 2) - 1] + arr[n / 2]) / (double)2;
  }

  return ans;
}

int main() {
  vector<int> arr = {90, 100, 78, 89, 67};

  cout << "INPUT(s):" << endl;
  printVector(arr, "  arr = ");

  double ans = solve(arr);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << ans << endl;

  return 0;
}
