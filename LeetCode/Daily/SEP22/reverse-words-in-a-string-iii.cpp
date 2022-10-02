//
// Created by adeshchoudhar on 22/9/22.
//

class Solution {
public:
    string reverseWords(string s) {
        string ans, str;
        for (char x: s) {
            if (x == ' ') {
                reverse(str.begin(), str.end());
                ans += str;
                ans.push_back(' ');
                str.clear();
            } else {
                str.push_back(x);
            }
        }
        reverse(str.begin(), str.end());
        ans += str;
        return ans;
    }
};
