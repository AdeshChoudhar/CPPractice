//
// Problem: Palindromic Array
//

#include "../../utils/utils.h"

bool isPalinArrayUtil(int num) {
  bool res;

  int tmp = num, rev = 0;

  while (tmp) {
    rev = rev * 10 + tmp % 10;
    tmp /= 10;
  }

  res = (num == rev);

  return res;
}

bool solve(vector<int> &arr) {
  bool ans = true;

  for (int i = 0, n = arr.size(); (i < n) && ans; i++) {
    ans = ans && (isPalinArrayUtil(arr[i]));
  }

  return ans;
}

int main() {
  vector<int> arr = {111, 222, 333, 444, 555};

  cout << "INPUT(s):" << endl;
  printVector(arr, "  arr = ");

  bool ans = solve(arr);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << (ans ? "true" : "false") << endl;

  return 0;
}
