// Problem: Specific pair in matrix

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX 1000

int solve(int[MAX][MAX], int);
void printArray(string, int[], int);

int main()
{
    int n = 5;
    int matrix[MAX][MAX] = {{1, 2, -1, -4, -20},
                            {-8, -3, 4, 2, 1},
                            {3, 8, 6, 1, 3},
                            {-4, -1, 1, 7, -6},
                            {0, -4, 10, -5, 1}};

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

    int ans = solve(matrix, n);

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = " << ans << endl;

    return 0;
}

int solve(int matrix[MAX][MAX], int n)
{
    int m, maxi = INT_MIN;
    int tmp[n][n];

    tmp[n - 1][n - 1] = matrix[n - 1][n - 1];

    m = matrix[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        m = max(m, matrix[n - 1][i]);
        tmp[n - 1][i] = m;
    }

    m = matrix[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        m = max(m, matrix[i][n - 1]);
        tmp[i][n - 1] = m;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            maxi = max(maxi, (tmp[i + 1][j + 1] - matrix[i][j]));
            tmp[i][j] = max(matrix[i][j], max(tmp[i][j + 1], tmp[i + 1][j]));
        }
    }

    return maxi;
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
