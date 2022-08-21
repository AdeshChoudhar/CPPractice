class Solution
{
public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n)
    {
        bool ans = false;
        if (n != 0)
        {
            double res = log2(n);
            ans = (ceil(res) == floor(res));
        }
        return ans;
    }
};
