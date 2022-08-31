class Solution
{
public:
    int findSwapValues(int A[], int n, int B[], int m)
    {
        int ans = -1, res = accumulate(A, A + n, 0) - accumulate(B, B + m, 0);
        unordered_set<int> us;
        for (int i = 0; i < m; i++)
        {
            us.insert(res + 2 * B[i]);
        }
        for (int i = 0; (i < n) && (ans == -1); i++)
        {
            if (us.find(2 * A[i]) != us.end())
            {
                ans = 1;
            }
        }
        return ans;
    }
};
