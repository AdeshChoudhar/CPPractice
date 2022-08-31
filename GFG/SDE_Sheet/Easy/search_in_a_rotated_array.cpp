class Solution
{
public:
    int search(int A[], int l, int h, int key)
    {
        int ans = -1, m;
        while (l <= h)
        {
            int m = l + (h - l) / 2;
            if (A[m] == key)
            {
                ans = m;
                break;
            }
            else if (A[l] <= A[m])
            {
                if ((A[l] <= key) && (key <= A[m]))
                {
                    h = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }
            else
            {
                if ((A[m] <= key) && (key <= A[h]))
                {
                    l = m + 1;
                }
                else
                {
                    h = m - 1;
                }
            }
        }
        return ans;
    }
};
