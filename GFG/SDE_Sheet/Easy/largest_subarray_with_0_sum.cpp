class Solution
{
public:
    int maxLen(vector<int> &A, int n)
    {
        int ans = 0, sum = 0;
        unordered_map<int, int> um;
        for (int i = 0; i < n; i++)
        {
            sum += A[i];
            if (sum == 0)
            {
                ans = max(ans, i + 1);
            }
            else if (um.find(sum) != um.end())
            {
                ans = max(ans, i - um[sum]);
            }
            else
            {
                um[sum] = i;
            }
        }
        return ans;
    }
};
