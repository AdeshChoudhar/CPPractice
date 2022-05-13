// Problem: Factorials of large numbers

#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<int> solve(int);
void fact(vector<int> &, int);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N = 10;

    cout << "INPUT(s):" << endl;
    cout << "\tN = " << N << endl;

    vector<int> ans = solve(N);

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = ";
    for (int i = 0, n = ans.size(); i < n; i++)
    {
        cout << ans[i];
    }
    cout << endl;

    return 0;
}

vector<int> solve(int N)
{
    vector<int> v = {1};
    fact(v, N);
    return v;
}

void fact(vector<int> &v, int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }

    fact(v, n - 1);

    int k = 0, c = 0;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        k = v[i];
        v[i] = (k * n + c) % 10;
        c = (k * n + c) / 10;
    }

    while (c > 0)
    {
        v.insert(v.begin(), c % 10);
        c = c / 10;
    }
}
