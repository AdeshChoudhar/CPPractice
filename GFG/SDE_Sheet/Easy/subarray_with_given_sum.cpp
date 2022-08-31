class Solution
{
public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        vector<int> ans = {-1};
        long long sum = arr[0];
        for (int i = 1, j = 0; i <= n; i++)
        {
            while ((sum > s) && (j < (i - 1)))
            {
                sum -= arr[j];
                j += 1;
            }
            if (sum == s)
            {
                ans = {j, i - 1};
                break;
            }
            if (i < n)
            {
                sum += arr[i];
            }
        }
        return ans;
    }
};
