class Solution
{
public:
    vector<vector<int>> rotateMatrix(int M, int N, vector<vector<int>> Mat)
    {
        int t = 0, r = N - 1, b = M - 1, l = 0;
        while ((l < r) && (t < b))
        {
            int x = Mat[t + 1][l];
            for (int i = l; i <= r; i++)
            {
                swap(x, Mat[t][i]);
            }
            t++;
            for (int i = t; i <= b; i++)
            {
                swap(x, Mat[i][r]);
            }
            r--;
            for (int i = r; i >= l; i--)
            {
                swap(x, Mat[b][i]);
            }
            b--;
            for (int i = b; i >= t; i--)
            {
                swap(x, Mat[i][l]);
            }
            l++;
        }
        return Mat;
    }
};
