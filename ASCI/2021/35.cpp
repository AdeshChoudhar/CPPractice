// Problem: Find the median

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int solve(vector<int>);
void printArray(string, vector<int>, int);

int main()
{
    vector<int> v = {90, 100, 78, 89, 67};
    int n = v.size();

    cout << "INPUT(s):" << endl;
    printArray("arr", v, n);

    int ans = solve(v);

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = " << ans << endl;

    return 0;
}

int solve(vector<int> v)
{
    sort(v.begin(), v.end());

    int median;
    if (v.size() % 2)
    {
        median = v[v.size() / 2];
    }
    else
    {
        median = (v[(v.size() / 2) - 1] + v[v.size() / 2]) / 2;
    }

    return median;
}

void printArray(string s, vector<int> v, int n)
{
    cout << "\t" << s << " = { ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << ", ";
    }
    cout << "}" << endl;
}
