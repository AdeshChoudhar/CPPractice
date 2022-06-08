//
// Problem: Implement an algorithm to determine if a string has all unique
//          characters. What if you cannot use additional data structures?
//

#include <bits/stdc++.h>
using namespace std;

bool solve(string &);

int main()
{
    string str = "unique";
    cout << "INPUT(s):" << endl;
    cout << "\tstr = " << str << endl;

    bool ans = solve(str);

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = " << ans << endl;
    return 0;
}

bool solve(string &str)
{
    bool ans = true;
    sort(str.begin(), str.end());
    for (int i = 0, n = str.length(); i < n; i++)
    {
        if (str[i] == str[i + 1])
        {
            ans = false;
            break;
        }
    }
    return ans;
}
