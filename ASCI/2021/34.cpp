// Problem: Palindromic array

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int solve(int[], int);
bool palindrome(int);
void printArray(string, int[], int);

int main()
{
    int arr[] = {111, 222, 333, 444, 555};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "INPUT(s):" << endl;
    printArray("arr", arr, n);

    string ans = solve(arr, n) ? "Yes" : "No";

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = " << ans << endl;

    return 0;
}

int solve(int arr[], int n)
{
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        if (!(palindrome(arr[i])))
        {
            flag = 0;
            break;
        }
    }

    return flag;
}

bool palindrome(int n)
{
    int tmp = n, rev = 0;
    while (tmp)
    {
        rev = rev * 10 + tmp % 10;
        tmp /= 10;
    }

    return (n == rev);
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
