//
// Problem: Next Permutation
//

#include "../../utils/utils.h"

void solve(vector<int> &arr) {
  int pvt = -1, n = arr.size();
  for (int i = n - 2; i >= 0; i--) {
    if (arr[i] < arr[i + 1]) {
      pvt = i;
      break;
    }
  }

  if (pvt == -1) {
    reverse(arr.begin(), arr.end());
    return;
  }

  for (int i = n - 1; i > pvt; i--) {
    if (arr[i] > arr[pvt]) {
      swap(arr[i], arr[pvt]);
      break;
    }
  }

  reverse(arr.begin() + pvt + 1, arr.end());
}

int main() {
  vector<int> arr = {2, 4, 1, 7, 5, 0};

  cout << "INPUT(s):" << endl;
  printVector(arr, "  arr = ");

  solve(arr);

  cout << "OUTPUT(s):" << endl;
  printVector(arr, "  arr = ");

  return 0;
}
