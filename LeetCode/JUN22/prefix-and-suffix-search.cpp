//
// Created by adeshchoudhar on 18/06/22.
//

class TrieNode {
public:
    int idx;
    unordered_map<char, TrieNode *> children;

    TrieNode() {
        this->idx = 0;
        children.clear();
    }
};

class WordFilter {
public:
    TrieNode *root;

    WordFilter(vector <string> &words) {
        root = new TrieNode();
        string word;
        for (int idx = 0, n = words.size(); idx < n; idx++) {
            word = words[idx] + "#";
            for (int i = 0, m = word.length(); i < m; i++) {
                TrieNode *current = root;
                current->idx = idx;
                for (int j = i; j < 2 * m - 1; j++) {
                    if (current->children.find(word[j % m]) == current->children.end()) {
                        current->children[word[j % m]] = new TrieNode();
                    }
                    current = current->children[word[j % m]];
                    current->idx = idx;
                }
            }
        }
    }

    int f(string prefix, string suffix) {
        int idx = -1;
        TrieNode *current = root;
        string word = suffix + "#" + prefix;
        for (char c: word) {
            if (current->children.find(c) == current->children.end()) {
                return idx;
            }
            current = current->children[c];
        }
        idx = current->idx;
        return idx;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
