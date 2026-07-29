//
// Problem: Merge Without Extra Space
//

#include "../../utils/utils.h"

void solve(vector<int> &a, vector<int> &b) {
  int m = a.size(), n = b.size();
  for (int i = m - 1, j = 0; (i >= 0) && (j < n);) {
    if (a[i] <= b[j]) {
      break;
    }

    swap(a[i], b[j]);

    i -= 1;
    j += 1;
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
}

int main() {
  vector<int> a = {2, 4, 7, 10};
  vector<int> b = {2, 3};

  cout << "INPUT(s):" << endl;
  printVector(a, "  a = ");
  printVector(b, "  b = ");

  solve(a, b);

  cout << "OUTPUT(s):" << endl;
  printVector(a, "  a = ");
  printVector(b, "  b = ");

  return 0;
}
