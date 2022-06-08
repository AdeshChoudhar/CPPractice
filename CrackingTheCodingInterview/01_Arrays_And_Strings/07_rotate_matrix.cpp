//
// Problem: Given an image represented by an NxN matrix, where each pixel in the
//          image is 4 bytes, write a method to rotate the image by 90 degrees.
//          Can you do this in place?
//

#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &);
void printArray(string, vector<int> &, int);

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    cout << "INPUT(s):" << endl;
    for (int i = 0, n = matrix.size(); i < n; i++)
    {
        if (i == 0)
        {
            printArray("matrix = ", matrix[i], n);
        }
        else
        {
            printArray("         ", matrix[i], n);
        }
    }

    solve(matrix);

    cout << "OUTPUT(s):" << endl;
    for (int i = 0, n = matrix.size(); i < n; i++)
    {
        if (i == 0)
        {
            printArray("matrix = ", matrix[i], n);
        }
        else
        {
            printArray("         ", matrix[i], n);
        }
    }
    return 0;
}

void solve(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
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
