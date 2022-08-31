//
// Created by adeshchoudhar on 20/10/21.
//

class Solution {
public:
    string reverseWords(string s) {
        vector <string> words;
        string word = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (word.compare("")) {
                    words.push_back(word);
                    word = "";
                }
            } else {
                word += s[i];
            }
        }
        if (word.compare("")) {
            words.push_back(word);
        }

        string ans = words[0];
        for (int i = 1; i < words.size(); i++) {
            ans = words[i] + " " + ans;
        }
        return ans;
    }
};
