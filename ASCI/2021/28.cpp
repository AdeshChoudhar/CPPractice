//
// Problem: Triplet Sum in Array
//

#include "../../utils/utils.h"

bool solve(vector<int> &arr, int target) {
  bool ans = false;

  sort(arr.begin(), arr.end());

  for (int i = 0, n = arr.size(); i < (n - 2); i++) {
    int l = i + 1, r = n - 1;
    while (l < r) {
      int sum = arr[i] + arr[l] + arr[r];
      if (sum < target) {
        l += 1;
      } else if (sum > target) {
        r -= 1;
      } else {
        ans = true;
        return ans;
      }
    }
  }

  return ans;
}

int main() {
  vector<int> arr = {1, 4, 45, 6, 10, 8};
  int target = 13;

  cout << "INPUT(s):" << endl;
  printVector(arr, "  arr = ");
  cout << "  target = " << target << endl;

  bool ans = solve(arr, target);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << (ans ? "true" : "false") << endl;

  return 0;
}
