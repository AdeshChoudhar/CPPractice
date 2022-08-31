class Solution
{
public:
    string chooseandswap(string a)
    {
        string ans = a;
        const int n = 26;
        vector<bool> v(n, false);
        for (char x : a)
        {
            v[x - 'a'] = true;
        }
        int first = find(v.begin(), v.end(), true) - v.begin();
        int second = find(v.rbegin(), v.rend(), true) - v.rbegin();
        if (first == second)
        {
            return ans;
        }
        string res;
        for (char x : a)
        {
            if (x == ('a' + first))
            {
                res.push_back('a' + second);
            }
            else if (x == ('a' + second))
            {
                res.push_back('a' + first);
            }
            else
            {
                res.push_back(x);
            }
        }
        ans = min(ans, res);
        return ans;
    }
};
