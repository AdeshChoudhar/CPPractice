#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;
int exact_sum[61][61][61] = {};
int exact_num[61][61][61] = {};

int getSum(int X, int Y, int Z)
{
    long long ans = 0;
    exact_num[0][0][0] = 1;
    for (int i = 0; i <= X; i++)
    {
        for (int j = 0; j <= Y; j++)
        {
            for (int k = 0; k <= Z; k++)
            {
                if (i > 0)
                {
                    exact_sum[i][j][k] += (10 * exact_sum[i - 1][j][k] + 4 * exact_num[i - 1][j][k]) % MOD;
                    exact_num[i][j][k] += exact_num[i - 1][j][k] % MOD;
                }
                if (j > 0)
                {
                    exact_sum[i][j][k] += (10 * exact_sum[i][j - 1][k] + 5 * exact_num[i][j - 1][k]) % MOD;
                    exact_num[i][j][k] += exact_num[i][j - 1][k] % MOD;
                }
                if (k > 0)
                {
                    exact_sum[i][j][k] += (10 * exact_sum[i][j][k - 1] + 6 * exact_num[i][j][k - 1]) % MOD;
                    exact_num[i][j][k] += exact_num[i][j][k - 1] % MOD;
                }
                ans = (ans + exact_sum[i][j][k] % MOD) % MOD;
            }
        }
    }
    return ans;
}

int main()
{
    int X = 2, Y = 2, Z = 4;

    cout << "INPUT(s):" << endl;
    cout << "\tX = " << X << endl;
    cout << "\tY = " << Y << endl;
    cout << "\tZ = " << Z << endl;

    int ans = getSum(X, Y, Z);

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = " << ans << endl;

    return 0;
}
