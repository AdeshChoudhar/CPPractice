//
// Created by adeshchoudhar on 17/8/22.
//

class Solution {
public:
    int uniqueMorseRepresentations(vector <string> &words) {
        int ans;
        vector <string> morseCodes = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",
                                      ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",
                                      ".--", "-..-", "-.--", "--.."};
        set <string> s;
        for (string word: words) {
            string transformation;
            for (char x: word) {
                transformation += morseCodes[x - 'a'];
            }
            s.insert(transformation);
        }
        ans = s.size();
        return ans;
    }
};
