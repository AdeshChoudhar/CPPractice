class Solution
{
public:
    // Program for zig-zag conversion of array
    void zigZag(int arr[], int n)
    {
        for (int i = 1; i < n; i++)
        {
            if ((((i & 1) != 0) && (arr[i - 1] > arr[i])) ||
                (((i & 1) == 0) && (arr[i - 1] < arr[i])))
            {
                swap(arr[i - 1], arr[i]);
            }
        }
    }
};
