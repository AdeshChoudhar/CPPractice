//
// Problem: Given a string, write a function to check if it is a permutation of
//          a palin­drome. A palindrome is a word or phrase that is the same
//          forwards and backwards. A permutation is a rearrangement of letters.
//          The palindrome does not need to be limited to just dictionary words.
//

#include <bits/stdc++.h>
using namespace std;

bool solve(string &);

int main()
{
    string str = "Tact Coa";
    cout << "INPUT(s):" << endl;
    cout << "\tstr = " << str << endl;

    bool ans = solve(str);

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = " << ans << endl;
    return 0;
}

bool solve(string &str)
{
    bool ans;
    bitset<26> bs;
    for (char x : str)
    {
        if (islower(x))
        {
            bs[x - 'a'].flip();
        }
        else if (isupper(x))
        {
            bs[tolower(x) - 'a'].flip();
        }
    }
    ans = (bs.count() <= 1);
    return ans;
}
