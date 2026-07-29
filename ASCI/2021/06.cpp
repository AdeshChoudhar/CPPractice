//
// Problem: Union of Arrays with Duplicates
//

#include "../../utils/utils.h"

vector<int> solve(vector<int> &a, vector<int> &b) {
  vector<int> ans;

  unordered_set<int> us;

  for (int x : a) {
    us.insert(x);
  }

  for (int x : b) {
    us.insert(x);
  }

  for (int x : us) {
    ans.push_back(x);
  }

  return ans;
}

int main() {
  vector<int> a = {1, 2, 3, 2, 1};
  vector<int> b = {3, 2, 2, 3, 3, 2};

  cout << "INPUT(s):" << endl;
  printVector(a, "  a = ");
  printVector(b, "  b = ");

  vector<int> ans = solve(a, b);

  cout << "OUTPUT(s):" << endl;
  printVector(ans, "  ans = ");

  return 0;
}
