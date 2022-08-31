class Solution
{
public:
    int idx;
    vector<int> ans;

    Solution()
    {
        this->idx = 0;
    }

    vector<int> sortedArrayToBST(vector<int> &nums)
    {
        int n = nums.size();
        this->ans.resize(n, 0);
        sortedArrayToBSTUtil(nums, 0, n - 1);
        return this->ans;
    }

    void sortedArrayToBSTUtil(vector<int> &nums, int low, int high)
    {
        if (low > high)
        {
            return;
        }
        int mid = low + (high - low) / 2;
        this->ans[this->idx] = nums[mid];
        this->idx += 1;
        sortedArrayToBSTUtil(nums, low, mid - 1);
        sortedArrayToBSTUtil(nums, mid + 1, high);
    }
};
