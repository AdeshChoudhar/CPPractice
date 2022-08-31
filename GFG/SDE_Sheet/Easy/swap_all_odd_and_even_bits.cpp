class Solution
{
public:
    // Function to swap odd and even bits.
    unsigned int swapBits(unsigned int n)
    {
        unsigned int ans = 0;
        for (int i = 0; i < 32; i += 2)
        {
            if (((n >> (i + 1)) & 1) == 1)
            {
                ans += (unsigned int)pow(2, i);
            }
            if (((n >> (i)) & 1) == 1)
            {
                ans += (unsigned int)pow(2, i + 1);
            }
        }
        return ans;
    }
};
