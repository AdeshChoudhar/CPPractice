int longestSubstrDistinctChars(string S)
{
    int ans = 0, n = S.length(), l = 0, r = 0;
    unordered_set<char> us;
    while (r < n)
    {
        if (us.find(S[r]) == us.end())
        {
            us.insert(S[r]);
        }
        else
        {
            ans = max(ans, r - l);
            while (S[l] != S[r])
            {
                us.erase(us.find(S[l]));
                l += 1;
            }
            us.erase(us.find(S[l]));
            l += 1;
            us.insert(S[r]);
        }
        r += 1;
    }
    ans = max(ans, r - l);
    return ans;
}
