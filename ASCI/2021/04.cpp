//
// Problem: Sort 0s, 1s and 2s
//

#include "../../utils/utils.h"

void solve(vector<int> &arr) {
  int low = 0, mid = 0, hih = arr.size() - 1;
  while (mid <= hih) {
    if (arr[mid] == 0) {
      swap(arr[low], arr[mid]);
      low += 1;
      mid += 1;
    } else if (arr[mid] == 1) {
      mid += 1;
    } else {
      swap(arr[mid], arr[hih]);
      hih -= 1;
    }
  }
}

int main() {
  vector<int> arr = {0, 1, 2, 0, 1, 2};

  cout << "INPUT(s):" << endl;
  printVector(arr, "  arr = ");

  solve(arr);

  cout << "OUTPUT(s):" << endl;
  printVector(arr, "  arr = ");

  return 0;
}
