// Problem: Rearrange the array alternate positive and negative numbers with O(1) extra space

#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve(int[], int);
void rightRotate(int[], int, int, int);
void printArray(string, int[], int);

int main()
{
    int arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
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
    int l = -1;
    for (int i = 0; i < n; i++)
    {
        if (l >= 0)
        {
            if (((arr[i] >= 0) && (arr[l] < 0)) || ((arr[i] < 0) && (arr[l] >= 0)))
            {
                rightRotate(arr, n, l, i);
                if ((i - l) >= 2)
                {
                    l += 2;
                }
                else
                {
                    l = -1;
                }
            }
        }

        if (l == -1)
        {
            if (((arr[i] >= 0) && (!(i & 0x01))) || ((arr[i] < 0) && (i & 0x01)))
            {
                l = i;
            }
        }
    }
}

void rightRotate(int arr[], int n, int l, int r)
{
    int tmp = arr[r];
    for (int i = r; i > l; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[l] = tmp;
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
