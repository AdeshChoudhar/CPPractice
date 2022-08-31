class Solution
{
public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        bool ans = (((n >> k) & 1) == 1);
        return ans;
    }
};
