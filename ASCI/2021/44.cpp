// Problem: Rotate a matrix by 90 degree clockwise

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX 1000

void solve(int[MAX][MAX], int);
void printArray(string, int[], int);

int main()
{
    int n = 3;
    int matrix[MAX][MAX] = {{1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9}};

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

    solve(matrix, n);

    cout << "OUTPUT(s):" << endl;
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

    return 0;
}

void solve(int matrix[MAX][MAX], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = i; j < n - i - 1; j++)
        {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[n - 1 - j][i];
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
            matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
            matrix[j][n - 1 - i] = tmp;
        }
    }
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
