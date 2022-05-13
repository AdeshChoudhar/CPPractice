// Problem: Sort in increasing order the array of only 0s, 1s and 2s

#include <bits/stdc++.h>

using namespace std;

void solve(int[], int);
void printArray(string, int[], int);

int main()
{
    int arr[] = {0, 2, 1, 2, 0};
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
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        switch (arr[mid])
        {
        case 0:
            swap(arr[low++], arr[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(arr[mid++], arr[high--]);
            break;
        }
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
