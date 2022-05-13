// Problem: Move all negative numbers to beginning and positive to end with constant extra space

#include <bits/stdc++.h>

using namespace std;

void solve(int[], int);
void printArray(string, int[], int);

int main()
{
    int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
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
    int left = 0, right = n - 1;

    while (left <= right)
    {
        if (arr[left] < 0)
        {
            left++;
        }
        else if (arr[left] > 0 && arr[right] < 0)
        {
            swap(arr[left], arr[right]);
        }
        else if (arr[right] > 0)
        {
            right--;
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
