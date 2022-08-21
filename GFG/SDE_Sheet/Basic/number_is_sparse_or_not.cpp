class Solution
{
public:
    // Function to check if the number is sparse or not.
    bool isSparse(int n)
    {
        bool ans = true;
        const int m = 32;
        for (int i = 0; (i < (m - 1)) && ans; i++)
        {
            if ((n >> i) & (n >> (i + 1)) & 1)
            {
                ans = false;
            }
        }
        return ans;
    }
};
