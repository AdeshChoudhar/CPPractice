class Solution
{
public:
    string removeDups(string S)
    {
        string ans;
        set<char> s;
        for (char x : S)
        {
            if (s.find(x) == s.end())
            {
                ans.push_back(x);
                s.insert(x);
            }
        }
        return ans;
    }
};
