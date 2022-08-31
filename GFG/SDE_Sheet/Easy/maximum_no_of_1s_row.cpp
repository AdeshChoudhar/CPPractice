#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxOnes(vector<vector<int>> &Mat, int N, int M)
    {
        int ans = 0, mxm = 0, cnt;
        for (int i = 0; i < N; i++)
        {
            cnt = (int)(Mat[i].end() - lower_bound(Mat[i].begin(), Mat[i].end(), 1));
            if (cnt > mxm)
            {
                ans = i;
                mxm = cnt;
            }
        }
        return ans;
    }
};
