// Problem: Kth smallest element

#include <bits/stdc++.h>

using namespace std;

int solve(int[], int, int, int);
void printArray(string, int[], int);

int main()
{
    int arr[] = {7, 10, 4, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    cout << "INPUT(s):" << endl;
    printArray("arr", arr, n);
    cout << "\tk = " << k << endl;

    int ans = solve(arr, 0, n - 1, k);

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = " << ans << endl;

    return 0;
}

int solve(int arr[], int l, int r, int k)
{
    sort(arr, arr + r + 1);
    return arr[k - 1];
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
