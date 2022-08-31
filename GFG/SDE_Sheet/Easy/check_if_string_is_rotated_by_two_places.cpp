class Solution
{
public:
    // Function to check if a string can be obtained by rotating
    // another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        bool ans;
        string one = str1.substr(2) + str1.substr(0, 2);
        string two = str1.substr(str1.length() - 2) + str1.substr(0, str1.length() - 2);
        ans = (str2 == one) || (str2 == two);
        return ans;
    }
};
