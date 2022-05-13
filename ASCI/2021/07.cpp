// Problem: Cyclically rotate an array by one

#include <bits/stdc++.h>

using namespace std;

void solve(int[], int);
void printArray(string, int[], int);

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "INPUT(s):" << endl;
    printArray("arr", arr, n);

    solve(arr, n);

    cout << "OUTPUT(s):" << endl;
    printArray("arr", arr, n);

    return 0;
}

void solve(int arr[], int n)
{
    int last_value = arr[n - 1];
    for (int i = n - 1; i >= 1; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = last_value;
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
