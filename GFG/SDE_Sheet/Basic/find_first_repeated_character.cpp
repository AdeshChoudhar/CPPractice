string firstRepChar(string s)
{
    string ans = "-1";
    unordered_set<char> us;
    for (char x : s)
    {
        if (us.find(x) != us.end())
        {
            ans.clear();
            ans.push_back(x);
            break;
        }
        us.insert(x);
    }
    return ans;
}
