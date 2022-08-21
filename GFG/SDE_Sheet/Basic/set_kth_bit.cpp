class Solution
{
public:
    int setKthBit(int N, int K)
    {
        int ans = N | (1 << K);
        return ans;
    }
};
