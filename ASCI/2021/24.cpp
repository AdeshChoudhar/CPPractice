// Problem: Longest consecutive subsequence

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int solve(int[], int);
void printArray(string, int[], int);

int main()
{
    int arr[] = {2, 6, 1, 9, 4, 5, 3};
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
    set<int> s(arr, arr + n);
    vector<int> v(s.begin(), s.end());

    sort(v.begin(), v.end());

    int cnt = 1, maxi = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[i] - v[i - 1] == 1)
        {
            cnt += 1;
        }
        else
        {
            cnt = 1;
        }

        maxi = max(maxi, cnt);
    }

    return maxi;
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
