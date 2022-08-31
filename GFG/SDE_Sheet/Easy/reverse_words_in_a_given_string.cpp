class Solution
{
public:
    // Function to reverse words in a given string.
    string reverseWords(string S)
    {
        string ans, word;
        for (char x : S)
        {
            if (x == '.')
            {
                ans = "." + word + ans;
                word.clear();
            }
            else
            {
                word.push_back(x);
            }
        }
        ans = word + ans;
        return ans;
    }
};
