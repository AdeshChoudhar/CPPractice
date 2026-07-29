//
// Problem: Zero Sum Subarray
//

#include "../../utils/utils.h"

bool solve(vector<int> &arr) {
  bool ans;

  set<int> s = {0};

  int n = arr.size();
  for (int i = 0, sum = 0; i < n; i++) {
    sum += arr[i];
    s.insert(sum);
  }

  ans = (s.size() != (n + 1));

  return ans;
}

int main() {
  vector<int> arr = {4, 2, -3, 1, 6};

  cout << "INPUT(s):" << endl;
  printVector(arr, "  arr = ");

  bool ans = solve(arr);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << (ans ? "true" : "false") << endl;

  return 0;
}
