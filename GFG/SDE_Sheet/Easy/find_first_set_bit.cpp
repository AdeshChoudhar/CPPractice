class Solution
{
public:
    // Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        unsigned int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            if (((n >> i) & 1) == 1)
            {
                ans = i + 1;
                break;
            }
        }
        return ans;
    }
};
