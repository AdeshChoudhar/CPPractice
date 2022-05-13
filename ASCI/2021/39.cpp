// Problem: Median in a row-wise sorted matrix

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int solve(vector<vector<int>> &, int, int);
void printArray(string, vector<int>, int);

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5},
                                  {2, 6, 9},
                                  {3, 6, 9}};

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

    int ans = solve(matrix, matrix.size(), matrix[0].size());

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = " << ans << endl;

    return 0;
}

int solve(vector<vector<int>> &matrix, int r, int c)
{
    vector<int> v;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            v.push_back(matrix[i][j]);
        }
    }

    sort(v.begin(), v.end());

    int median;
    if (v.size() % 2)
    {
        median = v[v.size() / 2];
    }
    else
    {
        median = (v[(v.size() / 2) - 1] + v[v.size() / 2]) / 2;
    }

    return median;
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
