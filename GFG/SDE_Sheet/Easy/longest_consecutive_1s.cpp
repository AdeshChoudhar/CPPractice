class Solution
{
public:
    int maxConsecutiveOnes(int N)
    {
        int ans = 0, cnt = 0;
        for (int i = 0; i < 32; i++)
        {
            if (((N >> i) & 1) == 0)
            {
                ans = max(ans, cnt);
                cnt = 0;
            }
            else
            {
                cnt += 1;
            }
        }
        return ans;
    }
};