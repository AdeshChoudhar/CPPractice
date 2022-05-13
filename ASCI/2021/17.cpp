// Problem: Best time to buy and sell stocks

#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &);
void printArray(string, vector<int>, int);

int main()
{
    vector<int> v = {7, 1, 5, 3, 6, 4};
    cout << "INPUT(s):" << endl;
    printArray("arr", v, v.size());

    int ans = solve(v);

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = " << ans << endl;

    return 0;
}

int solve(vector<int> &v)
{
    int mini = INT_MAX, profit = 0;
    for (int i = 0, n = v.size(); i < n; i++)
    {
        mini = min(mini, v[i]);
        profit = max(profit, v[i] - mini);
    }

    return profit;
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
