// Problem: Chocolate distribution problem

#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll int solve(vector<ll int>, ll, ll);
void printArray(string, vector<ll int>, int);

int main()
{
    vector<ll int> v = {3, 4, 1, 9, 56, 7, 9, 12};
    int n = v.size();
    int m = 5;

    cout << "INPUT(s):" << endl;
    printArray("arr", v, n);
    cout << "\tm = " << m << endl;

    ll int ans = solve(v, n, m);

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = " << ans << endl;

    return 0;
}

ll int solve(vector<ll int> a, ll n, ll m)
{
    sort(a.begin(), a.end());

    ll int mini = INT_MAX;
    for (int i = 0; i < (n - m + 1); i++)
    {
        mini = min(mini, a[i + m - 1] - a[i]);
    }

    return mini;
}

void printArray(string s, vector<ll int> v, int n)
{
    cout << "\t" << s << " = { ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << ", ";
    }
    cout << "}" << endl;
}
