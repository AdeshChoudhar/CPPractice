class Solution
{
public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b)
    {
        int ans = 0, n = 32;
        for (int i = 0; i < 32; i++)
        {
            ans += (int)(((a >> i) & 1) ^ ((b >> i) & 1));
        }
        return ans;
    }
};
