// Problem: Minimum swaps and k together

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int solve(int[], int, int);
void printArray(string, int[], int);

int main()
{
    int arr[] = {2, 7, 9, 5, 8, 7, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 6;

    cout << "INPUT(s):" << endl;
    printArray("arr", arr, n);
    cout << "\tk = " << k << endl;

    int ans = solve(arr, n, k);

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = " << ans << endl;

    return 0;
}

int solve(int arr[], int n, int k)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
        {
            cnt += 1;
        }
    }

    int bad = 0;
    for (int i = 0; i < cnt; i++)
    {
        if (arr[i] > k)
        {
            bad += 1;
        }
    }

    int mini = bad;
    for (int i = 0, j = cnt; j < n; i++, j++)
    {
        if (arr[i] > k)
        {
            bad -= 1;
        }

        if (arr[j] > k)
        {
            bad += 1;
        }

        mini = min(mini, bad);
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
