// Problem: Maximum profit by buying and selling a share at most twice

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int solve(int[], int);
void printArray(string, int[], int);
void printArray(string, vector<int>, int);

int main()
{
    int arr[] = {2, 30, 15, 10, 8, 25, 80};
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
    vector<int> v(n, 0);

    int maxi = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
        }
        v[i] = max(v[i + 1], maxi - arr[i]);
    }

    int mini = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < mini)
        {
            mini = arr[i];
        }
        v[i] = max(v[i - 1], v[i] + (arr[i] - mini));
    }

    return v[n - 1];
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

void printArray(string s, vector<int> v, int n)
{
    cout << "\t" << s << " = { ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << ", ";
    }
    cout << "}" << endl;
}
