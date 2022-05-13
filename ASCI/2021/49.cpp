// Problem: Print all duplicates in string

#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<char> solve(string);
void printArray(string, vector<char>, int);

int main()
{
    string str = "test_string";

    cout << "INPUT(s):" << endl;
    cout << "\tstr = " << str << endl;

    vector<char> ans = solve(str);

    cout << "OUTPUT(s):" << endl;
    printArray("ans", ans, ans.size());

    return 0;
}

vector<char> solve(string str)
{
    unordered_map<char, int> mp;
    for (auto x : str)
    {
        mp[x] += 1;
    }

    vector<char> v;
    for (auto x : mp)
    {
        if (x.second > 1)
        {
            v.push_back(x.first);
        }
    }

    return v;
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
