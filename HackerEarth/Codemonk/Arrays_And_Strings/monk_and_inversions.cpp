#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve();

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

void solve()
{
    int N;
    cin >> N;

    vector<vector<int>> M(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> M[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int p = i; p < N; p++)
            {
                for (int q = j; q < N; q++)
                {
                    if (M[i][j] > M[p][q])
                    {
                        ans += 1;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
