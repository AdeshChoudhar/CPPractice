class Solution
{
public:
    // Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        int ans = -1;
        for (int i = 0; i < 32; i++)
        {
            if ((((m >> i) & 1) ^ ((n >> i) & 1)) == 1)
            {
                ans = i + 1;
                break;
            }
        }
        return ans;
    }
};
