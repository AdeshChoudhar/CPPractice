class Solution
{
public:
    int firstElementKTime(int a[], int n, int k)
    {
        int ans = -1;
        unordered_map<int, int> um;
        for (int i = 0; i < n; i++)
        {
            um[a[i]] += 1;
            if (um[a[i]] == k)
            {
                ans = a[i];
                break;
            }
        }
        return ans;
    }
};
