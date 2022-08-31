class Solution
{
public:
    int toyCount(int N, int K, vector<int> arr)
    {
        int ans = 0, sum = 0;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < N; i++)
        {
            sum += arr[i];
            if (sum > K)
            {
                break;
            }
            ans += 1;
        }
        return ans;
    }
};
