//
// Problem: Assumeyou have a method isSubstringwhich checks if one word is a
//          substring of another. Given two strings, sl and s2, write code to
//          check if s2 is a rotation of sl using only one call to isSubstring
//          (e.g.,"waterbottle" is a rotation of"erbottlewat").
//

#include <bits/stdc++.h>
using namespace std;

bool solve(string &, string &);
bool isSubstring(string &, string &);

int main()
{
    string str1 = "waterbottle";
    string str2 = "erbottlewat";
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
    bool ans;
    string str = str2 + str2;
    ans = isSubstring(str, str1);
    return ans;
}

bool isSubstring(string &str1, string &str2)
{
    return (str1.find(str2) != string::npos);
}
