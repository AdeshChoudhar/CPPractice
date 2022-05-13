// Problem: Triplet sum in array

#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool solve(int[], int, int);
void printArray(string, int[], int);

int main()
{
    int arr[] = {1, 4, 45, 6, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 13;

    cout << "INPUT(s):" << endl;
    printArray("arr", arr, n);
    cout << "\tx = " << x << endl;

    string ans = solve(arr, n, x) ? "Yes" : "No";

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = " << ans << endl;

    return 0;
}

bool solve(int arr[], int n, int x)
{
    sort(arr, arr + n);

    bool flag = false;
    int l, r;
    for (int i = 0; i < n - 2; i++)
    {
        l = i + 1;
        r = n - 1;

        while (l < r)
        {
            if ((arr[i] + arr[l] + arr[r]) < x)
            {
                l += 1;
            }
            else if ((arr[i] + arr[l] + arr[r]) > x)
            {
                r -= 1;
            }
            else
            {
                flag = true;
                break;
            }
        }
    }

    return flag;
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
