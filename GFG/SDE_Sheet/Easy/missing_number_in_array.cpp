class Solution
{
public:
    int MissingNumber(vector<int> &array, int n)
    {
        int ans = (n * (n + 1)) / 2 - accumulate(array.begin(), array.end(), 0);
        return ans;
    }
};
