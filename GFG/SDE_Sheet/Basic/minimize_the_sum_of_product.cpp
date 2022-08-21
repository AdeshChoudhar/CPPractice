class Solution
{
public:
    long long int minValue(int a[], int b[], int n)
    {
        long long int ans = 0;
        sort(a, a + n);
        sort(b, b + n, greater<int>());
        for (int i = 0; i < n; i++)
        {
            ans += (a[i] * b[i]);
        }
        return ans;
    }
};
