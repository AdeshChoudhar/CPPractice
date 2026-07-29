//
// Problem: Three way partitioning
//

#include "../../utils/utils.h"

void solve(vector<int> &arr, int a, int b) {
  int low = 0, mid = 0, hih = arr.size() - 1;
  while (mid <= hih) {
    if (arr[mid] < a) {
      swap(arr[low], arr[mid]);
      mid += 1;
      low += 1;
    } else if (arr[mid] > b) {
      swap(arr[mid], arr[hih]);
      hih -= 1;
    } else {
      mid += 1;
    }
  }
}

int main() {
  vector<int> arr = {1, 2, 3, 3, 4};
  int a = 1, b = 2;

  cout << "INPUT(s):" << endl;
  printVector(arr, "  arr = ");
  cout << "  [a, b] = [" << a << ", " << b << "]" << endl;

  solve(arr, a, b);

  cout << "OUTPUT(s):" << endl;
  printVector(arr, "  arr = ");

  return 0;
}
