// Problem: Find the duplicate number

#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &);
void printArray(string, vector<int>, int);

int main()
{
    vector<int> v = {1, 3, 4, 2, 2};

    cout << "INPUT(s):" << endl;
    printArray("arr", v, v.size());

    int ans = solve(v);

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = " << ans << endl;

    return 0;
}

int solve(vector<int> &v)
{
    int i;
    for (i = 0; i < v.size(); i++)
    {
        if (v[abs(v[i])] > 0)
        {
            v[abs(v[i])] = -v[abs(v[i])];
        }
        else
        {
            break;
        }
    }

    return abs(v[i]);
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
