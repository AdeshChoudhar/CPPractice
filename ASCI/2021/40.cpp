// Problem: Rows with max 1s

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int solve(vector<vector<int>>, int, int);
void printArray(string, vector<int>, int);

int main()
{
    vector<vector<int>> matrix = {{0, 1, 1, 1},
                                  {0, 0, 1, 1},
                                  {1, 1, 1, 1},
                                  {0, 0, 0, 0}};

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

int solve(vector<vector<int>> matrix, int r, int c)
{
    int maxi = -1, R = -1, cnt = 0;
    for (int i = 0; i < r; i++)
    {
        cnt = count(matrix[i].begin(), matrix[i].end(), 1);
        if (cnt == 0)
        {
            continue;
        }
        if (cnt > maxi)
        {
            maxi = cnt;
            R = i;
        }
    }

    return R;
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
