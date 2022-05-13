// Problem: Common elements in all rows of a given matrix

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX 1000

vector<int> solve(int[MAX][MAX], int, int);
void printArray(string, int[], int);
void printArray(string, vector<int>, int);

int main()
{
    int m = 4;
    int n = 5;
    int matrix[MAX][MAX] = {{1, 2, 1, 4, 8},
                            {3, 7, 8, 5, 1},
                            {8, 7, 7, 3, 1},
                            {8, 1, 2, 7, 9}};

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

    vector<int> ans = solve(matrix, m, n);

    cout << "OUTPUT(s):" << endl;
    printArray("ans", ans, ans.size());

    return 0;
}

vector<int> solve(int matrix[MAX][MAX], int m, int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[matrix[0][i]] = 1;
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mp[matrix[i][j]] == i)
            {
                mp[matrix[i][j]] += 1;
            }
        }
    }

    vector<int> v;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second == m)
        {
            v.push_back(it->first);
        }
    }

    return v;
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

void printArray(string s, vector<int> v, int n)
{
    cout << "\t" << s << " = { ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << ", ";
    }
    cout << "}" << endl;
}
