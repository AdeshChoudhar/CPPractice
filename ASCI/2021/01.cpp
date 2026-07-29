//
// Problem: Reverse an Array
//

#include "../../utils/utils.h"

void solve(vector<int> &arr) {
  for (int i = 0, n = arr.size(); i < (n / 2); i++) {
    swap(arr[i], arr[n - 1 - i]);
  }
}

int main() {
  vector<int> arr = {1, 4, 3, 2, 6, 5};

  cout << "INPUT(s):" << endl;
  printVector(arr, "  arr = ");

  solve(arr);

  cout << "OUTPUT(s):" << endl;
  printVector(arr, "  arr = ");

  return 0;
}
