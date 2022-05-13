// Problem: Subarray with zero sum

#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool solve(int[], int);
void printArray(string, int[], int);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int arr[] = {4, 2, -3, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "INPUT(s):" << endl;
    printArray("arr", arr, n);

    string ans = solve(arr, n) ? "YES" : "NO";

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = " << ans << endl;

    return 0;
}

bool solve(int arr[], int n)
{
    set<int> s = {0};
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        s.insert(sum);
    }

    return (s.size() != n + 1);
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
