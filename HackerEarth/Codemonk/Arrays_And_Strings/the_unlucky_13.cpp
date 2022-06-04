#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000009

void solve();
void matrixMultiply(vector<vector<ll>> &, vector<vector<ll>> &);
void matrixExponential(vector<vector<ll>> &, ll);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}

vector<vector<ll>> M = {
    {0, 99, -10, 2},
    {1, 0, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 0, 10},
};

void solve()
{
    ll N;
    cin >> N;

    int ans;
    if (N == 0)
    {
        ans = 1;
    }
    else if (N == 1)
    {
        ans = 10;
    }
    else if (N == 2)
    {
        ans = 99;
    }
    else if (N == 3)
    {
        ans = 980;
    }
    else
    {
        vector<vector<ll>> A(M.begin(), M.end());
        matrixExponential(A, N - 3);
        ll a = A[3][3] * 1000;
        ll b = (A[0][0] * 20 + A[0][1] + 100 * A[0][3]) % mod;
        ans = (a - b + mod) % mod;
    }
    cout << ans << endl;
}

void matrixExponential(vector<vector<ll>> &A, ll N)
{
    if (N <= 1)
    {
        return;
    }
    matrixExponential(A, N / 2);
    matrixMultiply(A, A);
    if (N % 2 != 0)
    {
        matrixMultiply(A, M);
    }
}

void matrixMultiply(vector<vector<ll>> &A, vector<vector<ll>> &B)
{
    int N = 4;
    vector<vector<ll>> res(N, vector<ll>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                res[i][j] += (A[i][k] * B[k][j]);
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            A[i][j] = res[i][j] % mod;
        }
    }
}
