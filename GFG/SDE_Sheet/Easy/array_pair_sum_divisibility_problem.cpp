class Solution
{
public:
    bool canPair(vector<int> nums, int k)
    {
        bool ans, n = nums.size();
        unordered_map<int, int> um;
        for (int num : nums)
        {
            um[num % k] += 1;
        }
        ans = ((um[0] % 2) == 0) && (((k % 2) == 1) || (um[k / 2] % 2) == 0);
        for (int i = 1; i <= (k / 2 - (int)((k % 2) == 0)); i++)
        {
            ans = (ans && (um[i] == um[k - i]));
        }
        return ans;
    }
};
