//
// Problem: Alternate Positive Negative
//

#include "../../utils/utils.h"

void solve(vector<int> &arr) {
  vector<int> pos, neg;

  for (int x : arr) {
    if (x >= 0) {
      pos.push_back(x);
    } else {
      neg.push_back(x);
    }
  }

  int i = 0, pi = 0, pn = pos.size(), ni = 0, nn = neg.size();

  for (; (pi < pn) && (ni < nn); i++) {
    if ((i % 2) == 0) {
      arr[i] = pos[pi];
      pi += 1;
    } else {
      arr[i] = neg[ni];
      ni += 1;
    }
  }

  for (; pi < pn; pi++, i++) {
    arr[i] = pos[pi];
  }

  for (; ni < nn; ni++, i++) {
    arr[i] = neg[ni];
  }
}

int main() {
  vector<int> arr = {9, 4, -2, -1, 5, 0, -5, -3, 2};

  cout << "INPUT(s):" << endl;
  printVector(arr, "  arr = ");

  solve(arr);

  cout << "OUTPUT(s):" << endl;
  printVector(arr, "  arr = ");

  return 0;
}
