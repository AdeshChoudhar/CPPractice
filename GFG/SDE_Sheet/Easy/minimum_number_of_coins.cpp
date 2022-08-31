class Solution
{
public:
    vector<int> minPartition(int N)
    {
        vector<int> ans;
        vector<int> v = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        for (int i = N; i != 0;)
        {
            for (int x : v)
            {
                if (x <= i)
                {
                    i -= x;
                    ans.push_back(x);
                    break;
                }
            }
        }
        return ans;
    }
};
