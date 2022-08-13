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

    vector<int> H(N);
    for (int i = 0; i < N; i++)
    {
        cin >> H[i];
    }

    int ans = -1;
    map<int, int> mp;
    for (int h : H)
    {
        mp[h] += 1;
    }
    set<int> s;
    for (auto x : mp)
    {
        s.insert(x.second);
    }
    vector<int> v(s.begin(), s.end());
    sort(v.begin(), v.end());
    if (v.size() != 1)
    {
        ans = v.back() - v.front();
    }
    cout << ans << endl;
}
