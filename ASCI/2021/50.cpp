//
// Problem: Number Formation
//

#include "../../utils/utils.h"

int getSum(int x, int y, int z) {
  int ans;

  long long res = 0LL;
  const int MOD = (int)(1e9 + 7);

  vector<vector<vector<long long>>> dpSum(
      x + 1, vector<vector<long long>>(y + 1, vector<long long>(z + 1, 0)));
  vector<vector<vector<long long>>> dpNum(
      x + 1, vector<vector<long long>>(y + 1, vector<long long>(z + 1, 0)));

  dpNum[0][0][0] = 1LL;

  for (int i = 0; i <= x; i++) {
    for (int j = 0; j <= y; j++) {
      for (int k = 0; k <= z; k++) {
        if (i > 0) {
          dpSum[i][j][k] = (dpSum[i][j][k] + (10 * dpSum[i - 1][j][k]) +
                            (4 * dpNum[i - 1][j][k])) %
                           MOD;
          dpNum[i][j][k] = (dpNum[i][j][k] + dpNum[i - 1][j][k]) % MOD;
        }

        if (j > 0) {
          dpSum[i][j][k] = (dpSum[i][j][k] + (10 * dpSum[i][j - 1][k]) +
                            (5 * dpNum[i][j - 1][k])) %
                           MOD;
          dpNum[i][j][k] = (dpNum[i][j][k] + dpNum[i][j - 1][k]) % MOD;
        }

        if (k > 0) {
          dpSum[i][j][k] = (dpSum[i][j][k] + (10 * dpSum[i][j][k - 1]) +
                            (6 * dpNum[i][j][k - 1])) %
                           MOD;
          dpNum[i][j][k] = (dpNum[i][j][k] + dpNum[i][j][k - 1]) % MOD;
        }

        res = (res + dpSum[i][j][k]) % MOD;
      }
    }
  }

  ans = res % MOD;

  return ans;
}

int main() {
  int x = 1, y = 1, z = 1;

  cout << "INPUT(s):" << endl;
  cout << "  x = " << x << endl;
  cout << "  y = " << y << endl;
  cout << "  z = " << z << endl;

  int ans = getSum(x, y, z);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << ans << endl;

  return 0;
}
