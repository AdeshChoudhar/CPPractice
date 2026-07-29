//
// Problem: Rotate Array by One
//

#include "../../utils/utils.h"

void solve(vector<int> &arr) {
  int b = arr.back();

  for (int i = arr.size() - 1; i >= 1; i--) {
    arr[i] = arr[i - 1];
  }

  arr[0] = b;
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5};

  cout << "INPUT(s):" << endl;
  printVector(arr, "  arr = ");

  solve(arr);

  cout << "OUTPUT(s):" << endl;
  printVector(arr, "  arr = ");

  return 0;
}
