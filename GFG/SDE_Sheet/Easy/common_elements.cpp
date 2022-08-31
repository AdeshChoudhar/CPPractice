class Solution
{
public:
    vector<int> common_element(vector<int> v1, vector<int> v2)
    {
        vector<int> ans;
        map<int, int> mp;
        for (int x : v1)
        {
            mp[x] += 1;
        }
        for (int x : v2)
        {
            if (mp[x] != 0)
            {
                ans.push_back(x);
                mp[x] -= 1;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
