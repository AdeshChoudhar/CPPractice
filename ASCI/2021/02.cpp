//
// Problem: Min and Max in Array
//

#include "../../utils/utils.h"

vector<int> solve(vector<int> &arr) {
  vector<int> ans = {INT_MAX, INT_MIN};

  for (int x : arr) {
    ans[0] = min(ans[0], x);
    ans[1] = max(ans[1], x);
  }

  return ans;
}

int main() {
  vector<int> arr = {1, 4, 3, -5, -4, 8, 6};

  cout << "INPUT(s):" << endl;
  printVector(arr, "  arr = ");

  vector<int> ans = solve(arr);

  cout << "OUTPUT(s):" << endl;
  printVector(ans, "  ans = ");

  return 0;
}
