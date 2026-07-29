//
// Problem: Move all negative elements to end
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

  int idx = 0;

  for (int x : pos) {
    arr[idx] = x;
    idx += 1;
  }

  for (int x : neg) {
    arr[idx] = x;
    idx += 1;
  }
}

int main() {
  vector<int> arr = {1, -1, 3, 2, -7, -5, 11, 6};

  cout << "INPUT(s):" << endl;
  printVector(arr, "  arr = ");

  solve(arr);

  cout << "OUTPUT(s):" << endl;
  printVector(arr, "  arr = ");

  return 0;
}
