// Problem: Search a 2D matrix

#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool solve(vector<vector<int>> &, int);
void printArray(string, vector<int>, int);

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 60}};
    int target = 3;

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
    cout << "\ttarget = " << target << endl;

    string ans = solve(matrix, target) ? "Yes" : "No";

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = " << ans << endl;

    return 0;
}

bool solve(vector<vector<int>> &matrix, int target)
{
    int r = matrix.size(), c = matrix[0].size();
    int x = 0, y = c - 1;
    while (x >= 0 && x < r && y >= 0 && y < c)
    {
        if (matrix[x][y] < target)
        {
            x++;
        }
        else if (matrix[x][y] > target)
        {
            y--;
        }
        else
        {
            return true;
        }
    }

    return false;
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
