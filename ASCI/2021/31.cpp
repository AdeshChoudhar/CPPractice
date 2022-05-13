// Problem: Smallest subarray with sum greater than x

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int solve(int[], int, int);
void printArray(string, int[], int);

int main()
{
    int arr[] = {1, 4, 45, 6, 0, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 51;

    cout << "INPUT(s):" << endl;
    printArray("arr", arr, n);

    int ans = solve(arr, n, x);

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = " << ans << endl;

    return 0;
}

int solve(int arr[], int n, int x)
{
    int s = 0, mini = n + 1, start = 0, end = 0;
    while (end < n)
    {
        while ((s <= x) && (end < n))
        {
            s += arr[end];
            end += 1;
        }

        while (s > x && start < n)
        {
            mini = min(mini, end - start);
            s -= arr[start];
            start += 1;
        }
    }

    return mini;
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
