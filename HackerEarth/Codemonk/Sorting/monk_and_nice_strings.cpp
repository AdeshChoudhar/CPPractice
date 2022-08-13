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
    int N;
    cin >> N;

    vector<string> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    vector<int> ans(N, 0);
    map<string, int> um;
    for (int i = 0; i < N; i++)
    {
        um[v[i]] += 1;
        for (auto it = um.begin(); it->first != v[i]; it++)
        {
            ans[i] += it->second;
        }
    }
    for (int x : ans)
    {
        cout << x << endl;
    }
}
