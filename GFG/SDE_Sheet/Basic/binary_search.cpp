class Solution
{
public:
    int binarysearch(int arr[], int n, int k)
    {
        int ans = -1, l = 0, r = n - 1, m;
        while (l <= r)
        {
            m = l + (r - l) / 2;
            if (arr[m] < k)
            {
                l = m + 1;
            }
            else if (arr[m] > k)
            {
                r = m - 1;
            }
            else
            {
                ans = m;
                break;
            }
        }
        return ans;
    }
};
