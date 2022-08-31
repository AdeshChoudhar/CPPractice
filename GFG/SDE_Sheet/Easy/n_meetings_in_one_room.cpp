class Solution
{
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        int ans = 1, lst;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i] = make_pair(end[i], start[i]);
        }
        sort(v.begin(), v.end());
        lst = v[0].first;
        for (int i = 1; i < n; i++)
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
