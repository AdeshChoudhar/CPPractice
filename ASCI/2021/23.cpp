// Problem: Maximum product subarray

#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll solve(int[], int);
void printArray(string, int[], int);

int main()
{
    int arr[] = {6, -3, -10, 0, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "INPUT(s):" << endl;
    printArray("arr", arr, n);

    ll int ans = solve(arr, n);

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = " << ans << endl;

    return 0;
}

ll int solve(int arr[], int n)
{
    ll int mini = arr[0], maxi = arr[0], max_product = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < 0)
        {
            swap(maxi, mini);
        }

        maxi = max((ll int)arr[i], maxi * arr[i]);
        mini = min((ll int)arr[i], mini * arr[i]);

        max_product = max(max_product, maxi);
    }

    return max_product;
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
