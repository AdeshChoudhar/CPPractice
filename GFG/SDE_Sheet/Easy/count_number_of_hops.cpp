class Solution
{
public:
    // Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        long long ans;
        int mod = (int)(1e9 + 7);
        vector<long long> dp = {1, 2, 4};
        if (n <= 3)
        {
            ans = dp[n - 1] % mod;
        }
        else
        {
            for (int i = 4; i <= n; i++)
            {
                dp[(i - 1) % 3] = (dp[0] + dp[1] + dp[2]) % mod;
            }
            ans = dp[(n - 1) % 3];
        }
        return ans;
    }
};
