class Solution
{
public:
    void sort012(int a[], int n)
    {
        for (int l = 0, m = 0, r = (n - 1); m <= r;)
        {
            if (a[m] == 0)
            {
                swap(a[m], a[l]);
                l += 1;
                m += 1;
            }
            else if (a[m] == 1)
            {
                m += 1;
            }
            else
            {
                swap(a[m], a[r]);
                r -= 1;
            }
        }
    }
};
