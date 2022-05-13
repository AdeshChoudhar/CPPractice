// Problem: Minimize the heights II

#include <bits/stdc++.h>

using namespace std;

int solve(int[], int, int);
void printArray(string, int[], int);

int main()
{
    int arr[] = {6, 1, 9, 1, 1, 7, 9, 5, 2, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

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
    if (n == 1)
    {
        return 0;
    }

    sort(arr, arr + n);

    int mini = arr[n - 1] - arr[0];
    int small = arr[0] + k;
    int big = arr[n - 1] - k;

    if (small > big)
    {
        swap(small, big);
    }

    for (int i = 1; i < n - 1; i++)
    {
        int subtract = arr[i] - k;
        int add = arr[i] + k;

        if (subtract >= small || add <= big)
        {
            continue;
        }

        if (big - subtract <= add - small)
        {
            small = subtract;
        }
        else
        {
            big = add;
        }
    }

    return min(mini, big - small);
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
