int strstr(string s, string x)
{
    int ans = -1;
    bool flag;
    for (int i = 0, m = s.length(), n = x.length(); i <= (m - n); i++)
    {
        flag = true;
        for (int j = 0; (j < n) && flag; j++)
        {
            if (s[i + j] != x[j])
            {
                flag = false;
            }
        }
        if (flag)
        {
            ans = i;
            break;
        }
    }
    return ans;
}
