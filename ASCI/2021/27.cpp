//
// Problem: Array Subset
//

#include "../../utils/utils.h"

bool solve(vector<int> &a, vector<int> &b) {
  bool ans = true;

  unordered_map<int, int> um;

  for (int i = 0, n = a.size(); i < n; i++) {
    um[a[i]] += 1;
  }

  for (int i = 0, m = b.size(); i < m; i++) {
    if (um[b[i]]) {
      um[b[i]] -= 1;
    } else {
      ans = false;
      return ans;
    }
  }

  return ans;
}

int main() {
  vector<int> a = {11, 7, 1, 13, 21, 3, 7, 3};
  vector<int> b = {11, 3, 7, 1, 7};

  cout << "INPUT(s):" << endl;
  printVector(a, "  a = ");
  printVector(b, "  b = ");

  bool ans = solve(a, b);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << (ans ? "true" : "false") << endl;

  return 0;
}
