// Problem: Reverse the array

#include <bits/stdc++.h>

using namespace std;

void solve(int[], int);
void printArray(string, int[], int);

int main()
{
    int arr[] = {4, 5, 1, 2};
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
    for (int i = 0; i < n / 2; i++)
    {
        int tmp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = tmp;
    }
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
