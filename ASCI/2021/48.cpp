// Problem: Palindrome string

#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool solve(string);

int main()
{
    string str = "abba";

    cout << "INPUT(s):" << endl;
    cout << "\tstr = " << str << endl;

    string ans = (solve(str) ? "Yes" : "No");

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = " << ans << endl;

    return 0;
}

bool solve(string str)
{
    for (int i = 0, n = str.size(); i < n / 2; i++)
    {
        if (str[i] != str[n - 1 - i])
        {
            return false;
        }
    }
    return true;
}
