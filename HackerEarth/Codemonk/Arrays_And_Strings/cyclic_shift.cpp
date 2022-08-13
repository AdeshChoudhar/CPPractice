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
    ll N, K;
    cin >> N >> K;

    string A;
    cin >> A;

    ll ans = 0;
    ll tmp = -1;
    string B;
    for (int i = 0; i < N; i++)
    {
        if (B < A)
        {
            B = A;
            ans = i;
        }
        else if (B == A)
        {
            tmp = (i - ans);
            break;
        }
        A = A.substr(1) + A.substr(0, 1);
    }
    if (tmp == -1)
    {
        ans += (K - 1) * N;
    }
    else
    {
        ans += (K - 1) * tmp;
    }
    cout << ans << endl;
}
