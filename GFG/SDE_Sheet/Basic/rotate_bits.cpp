class Solution
{
public:
    vector<int> rotate(int n, int d)
    {
        vector<int> ans;
        d %= 16;
        unsigned short int x = (n << d) | (n >> (16 - d));
        unsigned short int y = (n >> d) | (n << (16 - d));
        ans.push_back(x);
        ans.push_back(y);
        return ans;
    }
};
