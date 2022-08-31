class Solution
{
public:
    int romanToDecimal(string &str)
    {
        int ans = 0;
        unordered_map<char, int> um = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        for (int i = 0, n = str.length(); i < (n - 1); i++)
        {
            if (um[str[i]] < um[str[i + 1]])
            {
                ans -= um[str[i]];
            }
            else
            {
                ans += um[str[i]];
            }
        }
        ans += um[str.back()];
        return ans;
    }
};
