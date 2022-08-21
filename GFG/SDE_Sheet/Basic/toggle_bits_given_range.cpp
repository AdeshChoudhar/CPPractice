class Solution
{
public:
    int toggleBits(int N, int L, int R)
    {
        int ans = N;
        for (int i = L; i <= R; i++)
        {
            ans ^= (1 << (i - 1));
        }
        return ans;
    }
};
