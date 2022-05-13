// Problem: Array subset of another array

#include <bits/stdc++.h>

using namespace std;

#define ll long long

string solve(int[], int[], int, int);
void printArray(string, int[], int);

int main()
{
    int a[] = {11, 1, 13, 21, 3, 7};
    int b[] = {11, 3, 7, 1};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    cout << "INPUT(s):" << endl;
    printArray("a", a, n);
    printArray("b", b, m);

    string ans = solve(a, b, n, m);

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = " << ans << endl;

    return 0;
}

string solve(int a[], int b[], int n, int m)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[a[i]] += 1;
    }

    bool flag = true;
    for (int i = 0; i < m; i++)
    {
        if (mp[b[i]])
        {
            mp[b[i]] -= 1;
        }
        else
        {
            flag = false;
            break;
        }
    }

    string s = (flag ? "Yes" : "No");
    return s;
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
