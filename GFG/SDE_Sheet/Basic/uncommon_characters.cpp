class Solution
{
public:
    string UncommonChars(string A, string B)
    {
        string ans;
        const int n = 26;
        bitset<n> a, b;
        for (char x : A)
        {
            a[x - 'a'] = true;
        }
        for (char x : B)
        {
            b[x - 'a'] = true;
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i] ^ b[i])
            {
                ans.push_back('a' + i);
            }
        }
        sort(ans.begin(), ans.end());
        ans = ans.empty() ? "-1" : ans;
        return ans;
    }
};
