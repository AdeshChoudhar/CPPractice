class Solution
{
public:
    // Function to check if two arrays are equal or not.
    bool check(vector<ll> A, vector<ll> B, int N)
    {
        bool ans = true;
        unordered_map<ll, int> um;
        for (int x : A)
        {
            um[x] += 1;
        }
        for (int x : B)
        {
            um[x] -= 1;
        }
        for (auto x: um)
        {
            if (x.second != 0)
            {
                ans = false;
                break;
            }
        }
        return ans;
    }
};