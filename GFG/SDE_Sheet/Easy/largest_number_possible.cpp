class Solution
{
public:
    string findLargest(int N, int S)
    {
        string ans;
        if (S > (9 * N))
        {
            ans = "-1";
        }
        else if (S == 0)
        {
            if (N == 1)
            {
                ans = "0";
            }
            else
            {
                ans = "-1";
            }
        }
        else
        {
            for (int i = 0, s = S; i < N; i++)
            {
                if (s >= 9)
                {
                    ans.push_back('9');
                    s -= 9;
                }
                else if (s >= 0)
                {
                    ans.push_back('0' + s);
                    s = 0;
                }
            }
        }
        return ans;
    }
};
