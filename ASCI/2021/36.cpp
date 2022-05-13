// Problem: Median of two sorted arrays of different sizes

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int solve(int[], int[], int, int);
void printArray(string, int[], int);

int main()
{
    int a[] = {900};
    int b[] = {5, 8, 10, 20};

    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    cout << "INPUT(s):" << endl;
    printArray("a", a, n);
    printArray("b", b, m);

    int ans = solve(a, b, n, m);

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = " << ans << endl;

    return 0;
}

int solve(int a[], int b[], int n, int m)
{
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back(a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        v.push_back(b[i]);
    }

    sort(v.begin(), v.end());

    int median;
    if (v.size())
    {
        median = v[v.size() / 2];
    }
    else
    {
        median = (v[v.size() / 2 - 1] + v[v.size() / 2]) / 2;
    }

    return median;
}

void printArray(string s, int arr[], int n)
{
    cout << "\t" << s << " = { ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "}" << endl;
}
