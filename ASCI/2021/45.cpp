// Problem: Kth element in matrix

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX 1000

int solve(int[MAX][MAX], int, int);
int solveUtil(int[MAX][MAX], int, int);
void printArray(string, int[], int);

int main()
{
    int n = 4;
    int k = 3;
    int matrix[MAX][MAX] = {{16, 28, 60, 64},
                            {22, 41, 63, 91},
                            {27, 50, 87, 93},
                            {36, 78, 87, 94}};

    cout << "INPUT(s):" << endl;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            printArray("matrix =", matrix[i], n);
        }
        else
        {
            printArray("        ", matrix[i], n);
        }
    }
    cout << "\tk = " << k << endl;

    int ans = solve(matrix, n, k);

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = " << ans << endl;

    return 0;
}

int solve(int matrix[MAX][MAX], int n, int k)
{
    int l = matrix[0][0], r = matrix[n - 1][n - 1];
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        int ge_mid = solveUtil(matrix, n, mid);
        if (ge_mid >= k)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
}

int solveUtil(int matrix[MAX][MAX], int n, int mid)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][0] > mid)
        {
            return s;
        }
        if (matrix[i][n - 1] <= mid)
        {
            s += n;
            continue;
        }
        int g = 0;
        for (int jmp = n / 2; jmp >= 1; jmp /= 2)
        {
            while (g + jmp < n && matrix[i][g + jmp] <= mid)
            {
                g += jmp;
            }
        }
        s += g + 1;
    }
    return s;
}

void printArray(string s, int arr[], int n)
{
    cout << "\t" << s << " { ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "}" << endl;
}
