class Solution
{
public:
    string longestCommonPrefix(string arr[], int N)
    {
        string ans, str;
        int mxm = 0;
        for (int i = 0; i < N; i++)
        {
            if (arr[i].length() > mxm)
            {
                str = arr[i];
                mxm = arr[i].length();
            }
        }
        vector<int> dp(mxm, 0);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0, n = arr[i].length(); j < n; j++)
            {
                dp[j] += (int)(arr[i][j] == str[j]);
            }
        }
        for (int i = 0; i < mxm; i++)
        {
            if (dp[i] == N)
            {
                ans.push_back(str[i]);
            }
        }
        ans = ans.empty() ? "-1" : ans;
        return ans;
    }
};
