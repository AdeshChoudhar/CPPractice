#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}

void solve()
{
    string S;
    cin >> S;

    int k;
    cin >> k;

    string ans;
    vector<string> v;
    for (int i = 0, n = S.length(); i < n; i++)
    {
        v.push_back(S.substr(i));
    }
    sort(v.begin(), v.end());
    ans = v[k - 1];
    cout << ans << endl;
}
