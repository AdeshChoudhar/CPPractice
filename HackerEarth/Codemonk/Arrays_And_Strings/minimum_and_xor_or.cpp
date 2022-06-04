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

    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());
    int ans = INT_MAX;
    for (int i = 0; i < (N - 1); i++)
    {
        ans = min(ans, A[i] ^ A[i + 1]);
    }
    cout << ans << endl;
}
