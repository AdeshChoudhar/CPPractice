//
// Problem: Overlapping Intervals
//

#include "../../utils/utils.h"

struct cmp {
  bool operator()(vector<int> a, vector<int> b) const { return a[0] < b[0]; }
};

vector<vector<int>> solve(vector<vector<int>> &arr) {
  vector<vector<int>> ans;

  sort(arr.begin(), arr.end(), cmp());

  for (int i = 0, n = arr.size(); i < n; i++) {
    int beg = arr[i][0], end = arr[i][1];
    for (int j = i + 1; j < n; j++) {
      if (arr[j][0] > end) {
        break;
      } else {
        end = max(end, arr[j][1]);
        i += 1;
      }
    }

    ans.push_back({beg, end});
  }

  return ans;
}

int main() {
  vector<vector<int>> arr = {{1, 3}, {2, 4}, {6, 8}, {9, 10}};

  cout << "INPUT(s):" << endl;
  cout << "  arr = {\n";

  for (auto x : arr) {
    printVector(x, "    ");
  }

  cout << "  }" << endl;

  vector<vector<int>> ans = solve(arr);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = {\n";

  for (auto x : ans) {
    printVector(x, "    ");
  }

  cout << "  }" << endl;

  return 0;
}
