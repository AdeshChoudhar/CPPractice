string isSubset(int a1[], int a2[], int n, int m)
{
    string ans = "Yes";
    unordered_map<int, int> um;
    for (int i = 0; i < n; i++)
    {
        um[a1[i]] += 1;
    }
    for (int i = 0; (i < m) && (ans == "Yes"); i++)
    {
        if (um[a2[i]])
        {
            um[a2[i]] -= 1;
        }
        else
        {
            ans = "No";
        }
    }
    return ans;
}
