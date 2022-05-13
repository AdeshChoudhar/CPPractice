// Problem: Max rectangle

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000

int solve(int[MAX][MAX], int, int);
int getMaxArea(int[], int);
void printArray(string, int[], int);

int main()
{
    int n = 4;
    int m = 4;
    int matrix[MAX][MAX] = {{0, 1, 1, 0},
                            {1, 1, 1, 1},
                            {1, 1, 1, 1},
                            {1, 1, 0, 0}};

    cout << "INPUT(s):" << endl;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            printArray("matrix =", matrix[i], m);
        }
        else
        {
            printArray("        ", matrix[i], m);
        }
    }

    int ans = solve(matrix, n, m);

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = " << ans << endl;

    return 0;
}

int solve(int M[MAX][MAX], int n, int m)
{
    int area = 0, maxi = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i && M[i][j])
            {
                M[i][j] += M[i - 1][j];
            }
        }
        area = getMaxArea(M[i], m);
        maxi = max(maxi, area);
    }

    return maxi;
}

int getMaxArea(int arr[], int n)
{
    stack<int> s;
    int maxi = 0, top, area;

    int i = 0;
    while (i < n)
    {
        if (s.empty() || arr[s.top()] <= arr[i])
        {
            s.push(i);
            i += 1;
        }
        else
        {
            top = s.top();
            s.pop();
            area = arr[top] * (s.empty() ? i : i - s.top() - 1);
            maxi = max(maxi, area);
        }
    }

    while (s.empty() == false)
    {
        top = s.top();
        s.pop();
        area = arr[top] * (s.empty() ? i : i - s.top() - 1);
        maxi = max(maxi, area);
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
