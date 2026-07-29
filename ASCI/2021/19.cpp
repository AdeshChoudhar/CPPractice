//
// Problem: Common Elements
//

#include "../../utils/utils.h"

vector<int> solve(vector<int> &a, vector<int> &b) {
  vector<int> ans;

  unordered_map<int, int> um;

  for (int x : a) {
    um[x] += 1;
  }

  for (int x : b) {
    if (um[x] > 0) {
      ans.push_back(x);
      um[x] -= 1;
    }
  }

  sort(ans.begin(), ans.end());

  return ans;
}

int main() {
  vector<int> a = {3, 4, 2, 2, 4};
  vector<int> b = {3, 2, 2, 7};

  cout << "INPUT(s):" << endl;
  printVector(a, "  a = ");
  printVector(b, "  b = ");

  vector<int> ans = solve(a, b);

  cout << "OUTPUT(s):" << endl;
  printVector(ans, "  ans = ");

  return 0;
}
