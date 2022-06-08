//
// Problem: There are three types of edits that can be performed on strings:
//          insert a character, remove a character, or replace a character.
//          Given two strings, write a function to check if they are one edit
//          (or zero edits) away.
//

#include <bits/stdc++.h>
using namespace std;

bool solve(string &, string &);

int main()
{
    string str1 = "bale";
    string str2 = "pale";
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
    bool ans = false;
    int cnt = 0, i1 = 0, i2 = 0, n1 = str1.length(), n2 = str2.length();
    if (abs(n1 - n2) > 1)
    {
        return ans;
    }
    while ((i1 < n1) && (i2 < n2))
    {
        if (str1[i1] != str2[i2])
        {
            if (str1[i1 + 1] == str2[i2])
            {
                i1 += 1;
            }
            else if (str1[i1] == str2[i2 + 1])
            {
                i2 += 1;
            }
            cnt += 1;
        }
        i1 += 1;
        i2 += 1;
    }
    ans = (cnt < 2);
    return ans;
}
