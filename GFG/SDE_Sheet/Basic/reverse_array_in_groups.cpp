class Solution
{
public:
    // Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long> &arr, int n, int k)
    {
        for (int i = 0; i < n; i += k)
        {
            int m = ((i + k) < n) ? k : (n - i);
            for (int j = 0; j < m / 2; j++)
            {
                swap(arr[i + j], arr[i + (m - 1 - j)]);
            }
        }
    }
};
