//
// Problem: Stock Buy and Sell – Max 2 Transactions Allowed
//

#include "../../utils/utils.h"

int maxProfitUtil(vector<int> &arr, vector<vector<vector<int>>> &dp, int idx,
                  int cnt, int buy) {
  int res = 0;

  if ((cnt == 2) || (idx == arr.size())) {
    return res;
  }

  if (dp[idx][cnt][buy] != INT_MIN) {
    res = dp[idx][cnt][buy];
    return res;
  }

  int pick, drop;

  if (buy) {
    pick = -arr[idx] + maxProfitUtil(arr, dp, idx + 1, cnt, 0);
    drop = maxProfitUtil(arr, dp, idx + 1, cnt, buy);
  } else {
    pick = arr[idx] + maxProfitUtil(arr, dp, idx + 1, cnt + 1, 1);
    drop = maxProfitUtil(arr, dp, idx + 1, cnt, buy);
  }

  dp[idx][cnt][buy] = max(pick, drop);
  res = dp[idx][cnt][buy];

  return res;
}

int solve(vector<int> &arr) {
  int ans = 0;

  vector<vector<vector<int>>> dp(
      arr.size(), vector<vector<int>>(3, vector<int>(2, INT_MIN)));

  ans = maxProfitUtil(arr, dp, 0, 0, 1);

  return ans;
}

int main() {
  vector<int> arr = {10, 22, 5, 75, 65, 80};

  cout << "INPUT(s):" << endl;
  printVector(arr, "  arr = ");

  int ans = solve(arr);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << ans << endl;

  return 0;
}
