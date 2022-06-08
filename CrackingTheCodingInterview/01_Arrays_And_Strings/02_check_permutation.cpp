//
// Problem: Given two strings, write a method to decide if one is a permutation
//          of the other.
//

#include <bits/stdc++.h>
using namespace std;

bool solve(string &, string &);

int main()
{
    string str1 = "permutation";
    string str2 = "importunate";
    cout << "INPUT(s):" << endl;
    cout << "\tstr1 = " << str1 << endl;
    cout << "\tstr2 = " << str2 << endl;

    bool ans = solve(str1, str2);

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = " << ans << endl;
    return 0;
}

bool solve(string &str1, string &str2)
{
    bool ans = true;
    vector<int> v(26, 0);
    for (char x : str1)
    {
        v[x - 'a'] += 1;
    }
    for (char x : str2)
    {
        v[x - 'a'] -= 1;
    }
    for (int x : v)
    {
        if (x != 0)
        {
            ans = false;
            break;
        }
    }
    return ans;
}
