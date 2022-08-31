class Solution
{
public:
    vector<int> countDistinct(int A[], int n, int k)
    {
        vector<int> ans;
        unordered_map<int, int> um;
        int cnt = 0;
        for (int i = 0; i < k; i++)
        {
            cnt += (int)(um[A[i]] == 0);
            um[A[i]] += 1;
        }
        ans.push_back(cnt);
        for (int i = k; i < n; i++)
        {
            um[A[i - k]] -= 1;
            cnt -= (int)(um[A[i - k]] == 0);
            cnt += (int)(um[A[i]] == 0);
            um[A[i]] += 1;
            ans.push_back(cnt);
        }
        return ans;
    }
};
