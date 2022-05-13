// Problem: Count pairs with given sum

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int solve(int[], int, int);
void printArray(string, int[], int);

int main()
{
    int arr[] = {1, 5, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 6;

    cout << "INPUT(s):" << endl;
    printArray("arr", arr, n);

    int ans = solve(arr, n, k);

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = " << ans << endl;

    return 0;
}

int solve(int arr[], int n, int k)
{
    int cnt = 0;
    unordered_map<int, int> um;
    for (int i = 0; i < n; i++)
    {
        if (um.find(k - arr[i]) != um.end())
        {
            cnt += um[k - arr[i]];
        }
        um[arr[i]] += 1;
    }

    return cnt;
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
