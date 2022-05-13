// Problem: Count inversions

#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll int solve(ll[], ll);
void printArray(string, ll[], int);

int main()
{
    ll arr[] = {2, 4, 1, 3, 5};
    ll N = sizeof(arr) / sizeof(arr[0]);

    cout << "INPUT(s):" << endl;
    printArray("arr", arr, N);

    ll int ans = solve(arr, N);

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = " << ans << endl;

    return 0;
}

ll int mergeSort(ll arr[], ll int left, ll int right)
{
    if (left >= right)
    {
        return 0;
    }

    ll int mid = left + (right - left) / 2, i = left, j = mid + 1;
    ll int c = mergeSort(arr, left, mid) + mergeSort(arr, mid + 1, right);

    while (i <= mid)
    {
        while (j <= right && arr[i] > arr[j])
        {
            j++;
        }

        c += j - (mid + 1);
        i++;
    }

    sort(arr + left, arr + right + 1);

    return c;
}

ll int solve(ll arr[], ll N)
{
    return mergeSort(arr, 0, N - 1);
}

void printArray(string s, ll arr[], int n)
{
    cout << "\t" << s << " = { ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "}" << endl;
}
