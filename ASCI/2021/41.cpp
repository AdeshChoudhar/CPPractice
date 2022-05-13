// Problem: Sorted matrix

#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<vector<int>> solve(int, vector<vector<int>>);
void printArray(string, vector<int>, int);

int main()
{
    vector<vector<int>> matrix = {{10, 20, 30, 40},
                                  {15, 25, 35, 45},
                                  {27, 29, 37, 48},
                                  {32, 33, 39, 50}};

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

    vector<vector<int>> ans = solve(matrix.size(), matrix);

    cout << "OUTPUT(s):" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        if (i == 0)
        {
            printArray("ans =", ans[i], ans[i].size());
        }
        else
        {
            printArray("     ", ans[i], ans[i].size());
        }
    }

    return 0;
}

vector<vector<int>> solve(int n, vector<vector<int>> matrix)
{
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            v.push_back(matrix[i][j]);
        }
    }

    sort(v.begin(), v.end());

    vector<vector<int>> V;
    vector<int> tmp;
    for (int i = 0; i < n; i++)
    {
        tmp.clear();
        for (int j = 0; j < n; j++)
        {
            tmp.push_back(v[i * n + j]);
        }
        V.push_back(tmp);
    }

    return V;
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
