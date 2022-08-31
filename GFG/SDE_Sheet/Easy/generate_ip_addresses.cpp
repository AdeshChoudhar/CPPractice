class Solution
{
public:
    vector<string> ans;

    vector<string> genIp(string &s)
    {
        if (s.length() < 4)
        {
            return ans;
        }
        string cur;
        int idx = 0, par = 0;
        genIpUtil(s, idx, par, cur);
        return ans;
    }

    void genIpUtil(string &s, int idx, int par, string cur)
    {
        int n = s.length();
        if (par == 4)
        {
            if (idx == n)
            {
                cur.pop_back();
                ans.push_back(cur);
            }
            return;
        }
        for (int i = 0; (i < 3) && ((idx + i) < n); i++)
        {
            string sub = s.substr(idx, i + 1);
            if (stoi(sub) > 255 || (sub.length() > 1 && sub[0] == '0'))
            {
                continue;
            }
            string str = cur + sub + ".";
            genIpUtil(s, idx + i + 1, par + 1, str);
        }
    }
};
