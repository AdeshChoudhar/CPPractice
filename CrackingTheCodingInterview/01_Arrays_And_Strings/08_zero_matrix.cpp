//
// Problem: Write an algorithm such that if an element in an MxN matrix is 0,
//          its entire row and column are set to 0.
//

#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &);
void printArray(string, vector<int> &, int);

int main()
{
    vector<vector<int>> matrix = {
        {1, 1, 1, 1, 1},
        {1, 0, 2, 3, 1},
        {1, 4, 0, 6, 1},
        {1, 7, 8, 0, 1},
        {1, 1, 1, 1, 1},
    };
    int M = matrix.size(), N = matrix[0].size();
    cout << "INPUT(s):" << endl;
    for (int i = 0; i < M; i++)
    {
        if (i == 0)
        {
            printArray("matrix = ", matrix[i], N);
        }
        else
        {
            printArray("         ", matrix[i], N);
        }
    }

    solve(matrix);

    cout << "OUTPUT(s):" << endl;
    for (int i = 0; i < M; i++)
    {
        if (i == 0)
        {
            printArray("matrix = ", matrix[i], N);
        }
        else
        {
            printArray("         ", matrix[i], N);
        }
    }
    return 0;
}

void solve(vector<vector<int>> &matrix)
{
    bool row = false, col = false;
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                if (i == 0)
                {
                    row = true;
                }
                if (j == 0)
                {
                    col = true;
                }
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if ((matrix[i][0] == 0) || (matrix[0][j] == 0))
            {
                matrix[i][j] = 0;
            }
        }
    }
    if (row)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[0][i] = 0;
        }
    }
    if (col)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[i][0] = 0;
        }
    }
}

void printArray(string s, vector<int> &v, int n)
{
    cout << "\t" << s << "{ ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << ", ";
    }
    cout << "}" << endl;
}
