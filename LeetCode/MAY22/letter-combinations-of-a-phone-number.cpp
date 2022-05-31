//
// Created by adeshchoudhar on 09/05/22.
//

class Solution {
public:
    vector <string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector <string> letterCombinations(string digits) {
        vector <string> ans, tmp;
        if (digits.empty()) {
            return ans;
        }
        ans.push_back("");
        for (char digit: digits) {
            tmp.clear();
            for (char x: v[digit - '0']) {
                for (auto y: ans) {
                    tmp.push_back(y + x);
                }
            }
            swap(ans, tmp);
        }
        return ans;
    }
};
