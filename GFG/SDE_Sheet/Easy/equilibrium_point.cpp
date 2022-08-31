class Solution
{
public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n)
    {
        int ans = -1;
        long long sum = 0, total = 0;
        for (int i = 0; i < n; i++)
        {
            total += a[i];
        }
        for (int i = n - 1; (i >= 0) && (ans == -1); i--)
        {
            sum += a[i];
            if (total == sum)
            {
                ans = i + 1;
            }
            total -= a[i];
        }
        return ans;
    }
};
