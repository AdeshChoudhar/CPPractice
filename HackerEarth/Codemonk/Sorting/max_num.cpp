#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve();
ll int nCr(int, int);
ll int factorial(int);

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
    int N, l;
    cin >> N >> l;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    ll int ans = -1;
    int n = 30, sbs = 0;
    vector<ll int> idx(n, 0), vis(n, 1);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i] & (1 << j))
            {
                sbs += vis[j];
                idx[j] += (ll int)(1 << j);
                vis[j] = 0;
            }
        }
    }
    if (sbs >= l)
    {
        ans = 1;
        sort(idx.begin(), idx.end(), greater<ll int>());
        for (int i = 0; i < sbs; i++)
        {
            if (l <= 0)
            {
                break;
            }
            if (idx[i] != idx[i + 1])
            {
                l -= 1;
            }
            else
            {
                int cnt = 1;
                for (; (i != (sbs - 1)) && (idx[i] == idx[i + 1]); i++)
                {
                    cnt += 1;
                }
                if (cnt >= l)
                {
                    ans *= nCr(cnt, l);
                    break;
                }
                l -= cnt;
            }
        }
    }
    cout << ans << endl;
}

ll int nCr(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}

ll int factorial(int n)
{
    ll int res = 1;
    for (int i = 2; i <= n; i++)
    {
        res = res * i;
    }
    return res;
}
