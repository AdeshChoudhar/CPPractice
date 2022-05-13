// Problem: Minimum number of jumps

#include <bits/stdc++.h>

using namespace std;

int solve(int[], int);
void printArray(string, int[], int);

int main()
{
    int arr[] = {1, 4, 3, 2, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "INPUT(s):" << endl;
    printArray("arr", arr, n);

    int ans = solve(arr, n);

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = " << ans << endl;

    return 0;
}

int solve(int arr[], int n)
{
    if (n == 1)
        return 0;

    int mini = INT_MAX;
    for (int i = n - 2; i >= 0; i--)
    {
        if ((i + arr[i]) >= (n - 1))
        {
            int sub_mini = solve(arr, i + 1);
            if (sub_mini != INT_MAX)
            {
                mini = min(mini, sub_mini + 1);
            }
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
