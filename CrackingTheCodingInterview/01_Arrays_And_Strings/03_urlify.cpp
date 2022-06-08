//
// Problem: Write a method to replace all spaces in a string with '%20'. You may
//          assume that the string has sufficient space at the end to hold the
//          additional characters,and that you are given the "true" length of
//          the string. (Note: If implementing in Java, please use a character
//          array so that you can perform this operation in place.)
//

#include <bits/stdc++.h>
using namespace std;

void solve(string &, int);

int main()
{
    string str = "Mr John Smith    ";
    int len = 13;
    cout << "INPUT(s):" << endl;
    cout << "\tstr = " << str << endl;
    cout << "\tlen = " << len << endl;

    solve(str, len);
    string ans = str;

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = " << ans << endl;
    return 0;
}

void solve(string &str, int len)
{
    int l = len - 1, r = str.length() - 1;
    while (l >= 0)
    {
        if (str[l] == ' ')
        {
            str[r--] = '0';
            str[r--] = '2';
            str[r--] = '%';
        }
        else
        {
            str[r--] = str[l];
        }
        l -= 1;
    }
}
