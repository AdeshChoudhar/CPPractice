// Problem: Merge without extra space

#include <bits/stdc++.h>

using namespace std;

void solve(int[], int[], int, int);
void printArray(string, int[], int);

int main()
{
    int a[] = {1, 3, 5, 7};
    int b[] = {0, 2, 6, 8, 9};

    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    cout << "INPUT(s):" << endl;
    printArray("a", a, n);
    printArray("b", b, m);

    solve(a, b, n, m);

    cout << "OUTPUT(s):" << endl;
    printArray("a", a, n);
    printArray("b", b, m);

    return 0;
}

void solve(int a[], int b[], int n, int m)
{
    for (int i = m - 1; i >= 0; i--)
    {
        int j, last = a[n - 1];
        for (j = n - 2; j >= 0 && a[j] > b[i]; j--)
        {
            a[j + 1] = a[j];
        }

        if (j != n - 2 || last > b[i])
        {
            a[j + 1] = b[i];
            b[i] = last;
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
