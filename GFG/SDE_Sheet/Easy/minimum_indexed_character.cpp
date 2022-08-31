class Solution
{
public:
    // Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
    {
        int ans, n = str.length();
        unordered_map<char, int> um;
        for (char x : patt)
        {
            um[x] = n;
        }
        for (int i = 0; i < n; i++)
        {
            if (um.find(str[i]) != um.end())
            {
                um[str[i]] = min(um[str[i]], i);
            }
        }
        ans = n;
        for (auto x : um)
        {
            ans = min(ans, x.second);
        }
        ans = (ans == n) ? -1 : ans;
        return ans;
    }
};
