// Problem: Spirally traversing a matrix

#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<int> solve(vector<vector<int>>, int, int);
void printArray(string, vector<int>, int);

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};

    cout << "INPUT(s):" << endl;
    for (int i = 0, n = matrix.size(); i < n; i++)
    {
        if (i == 0)
        {
            printArray("matrix =", matrix[i], matrix[i].size());
        }
        else
        {
            printArray("        ", matrix[i], matrix[i].size());
        }
    }

    vector<int> ans = solve(matrix, matrix.size(), matrix[0].size());

    cout << "OUTPUT(s):" << endl;
    printArray("ans =", ans, ans.size());

    return 0;
}

vector<int> solve(vector<vector<int>> matrix, int r, int c)
{
    int row = 0;
    int col = 0;

    vector<int> v(r * c);

    int pos = 0;
    while (row < r && col < c)
    {
        for (int i = col; i < c; i++)
        {
            v[pos++] = matrix[row][i];
        }
        row++;

        for (int i = row; i < r; i++)
        {
            v[pos++] = matrix[i][c - 1];
        }
        c--;

        if (row < r)
        {
            for (int i = c - 1; i >= col; --i)
            {
                v[pos++] = matrix[r - 1][i];
            }
            r--;
        }

        if (col < c)
        {
            for (int i = r - 1; i >= row; --i)
            {
                v[pos++] = matrix[i][col];
            }
            col++;
        }
    }
    return v;
}

void printArray(string s, vector<int> v, int n)
{
    cout << "\t" << s << " { ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << ", ";
    }
    cout << "}" << endl;
}
