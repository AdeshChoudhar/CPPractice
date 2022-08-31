class Solution
{
public:
    // Function to find the maximum number of activities that can
    // be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        int ans = 0, lst = 0;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i] = make_pair(end[i], start[i]);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++)
        {
            if (v[i].second > lst)
            {
                lst = v[i].first;
                ans += 1;
            }
        }
        return ans;
    }
};
