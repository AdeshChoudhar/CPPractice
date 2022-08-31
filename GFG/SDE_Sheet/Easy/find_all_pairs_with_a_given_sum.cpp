class Solution
{
public:
    vector<pair<int, int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        vector<pair<int, int>> ans;
        unordered_set<int> us;
        for (int i = 0; i < M; i++)
        {
            us.insert(B[i]);
        }
        for (int i = 0; i < N; i++)
        {
            if (us.find(X - A[i]) != us.end())
            {
                ans.push_back(make_pair(A[i], X - A[i]));
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
