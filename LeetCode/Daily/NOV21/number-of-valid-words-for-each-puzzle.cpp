//
// Created by adeshchoudhar on 09/11/21.
//

class Solution {
public:
    vector<int> findNumOfValidWords(vector <string> &words, vector <string> &puzzles) {
        unordered_map<int, int> mp;
        for (auto word: words) {
            int mask = 0;
            for (auto c: word) {
                mask |= 1 << (int) (c - 'a');
            }
            mp[mask] += 1;
        }

        vector<int> ans;
        for (auto puzzle: puzzles) {
            int mask = 0;
            for (auto c: puzzle) {
                mask |= 1 << (int) (c - 'a');
            }

            int cnt = 0;
            int subMask = mask;
            int firstChar = 1 << (int) (puzzle[0] - 'a');
            while (subMask) {
                if (((subMask & firstChar) == firstChar) && (mp.find(subMask) != mp.end())) {
                    cnt += mp[subMask];
                }
                subMask = (subMask - 1) & mask;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
