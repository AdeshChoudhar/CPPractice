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
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    K %= N;
    for (int i = (N - K); i < N; i++)
    {
        cout << A[i] << " ";
    }
    for (int i = 0; i < (N - K); i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
