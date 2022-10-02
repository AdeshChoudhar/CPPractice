//
// Created by adeshchoudhar on 17/9/22.
//

struct TrieNode {
    int idx = -1;
    vector<int> indices;
    TrieNode *children[26] = {};
};

class Solution {
public:
    TrieNode *root;

    vector <vector<int>> palindromePairs(vector <string> &words) {
        vector <vector<int>> ans;
        root = new TrieNode();
        int n = words.size();
        for (int i = 0; i < n; i++) {
            insertWord(words[i], i);
        }
        for (int i = 0; i < n; i++) {
            TrieNode *cur = root;
            string &s = words[i];
            for (int j = 0, k = s.length(); (j < k) && (cur != nullptr); j++) {
                if ((cur->idx != -1) && (cur->idx != i) && isPalindrome(s, j, k - 1)) {
                    ans.push_back({i, cur->idx});
                }
                cur = cur->children[s[j] - 'a'];
            }
            if (cur != nullptr) {
                for (int j: cur->indices) {
                    if (i != j) {
                        ans.push_back({i, j});
                    }
                }
            }
        }
        return ans;
    }

    void insertWord(string &s, int idx) {
        TrieNode *cur = root;
        for (int i = s.size() - 1; i >= 0; i--) {
            int c = s[i] - 'a';
            if (cur->children[c] == nullptr) {
                cur->children[c] = new TrieNode();
            }
            if (isPalindrome(s, 0, i)) {
                cur->indices.push_back(idx);
            }
            cur = cur->children[c];
        }
        cur->indices.push_back(idx);
        cur->idx = idx;
    }

    bool isPalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }
};
