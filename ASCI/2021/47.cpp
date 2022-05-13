// Problem: Reverse a string

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(vector<char> &);
void printArray(string, vector<char>, int);

int main()
{
    vector<char> str = {'h', 'e', 'l', 'l', 'o'};

    cout << "INPUT(s):" << endl;
    printArray("str", str, str.size());

    solve(str);

    cout << "OUTPUT(s):" << endl;
    printArray("ans", str, str.size());

    return 0;
}

void solve(vector<char> &str)
{
    for (int i = 0, n = str.size(); i < n / 2; i++)
    {
        swap(str[i], str[n - 1 - i]);
    }
}

void printArray(string s, vector<char> v, int n)
{
    cout << "\t" << s << " = { ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << ", ";
    }
    cout << "}" << endl;
}
