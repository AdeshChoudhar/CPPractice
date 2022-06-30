//
// Created by adeshchoudhar on 20/06/22.
//

class TrieNode {
public:
    unordered_map<char, TrieNode *> children;
};

class Solution {
public:
    TrieNode *root;

    int minimumLengthEncoding(vector <string> &words) {
        int ans = 0;
        root = new TrieNode();
        vector <pair<TrieNode *, int>> leaves;
        for (auto word: unordered_set<string>(words.begin(), words.end())) {
            TrieNode *current = root;
            reverse(word.begin(), word.end());
            for (char c: word) {
                if (current->children.find(c) == current->children.end()) {
                    current->children[c] = new TrieNode();
                }
                current = current->children[c];
            }
            leaves.push_back(make_pair(current, word.length() + 1));
        }
        for (auto leaf: leaves) {
            if (leaf.first->children.empty()) {
                ans += leaf.second;
            }
        }
        return ans;
    }
};
