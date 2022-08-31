class Solution
{
public:
    // Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b)
    {
        bool ans = true;
        unordered_map<char, int> um;
        for (char x : a)
        {
            um[x] += 1;
        }
        for (char x : b)
        {
            um[x] -= 1;
        }
        for (auto x : um)
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
