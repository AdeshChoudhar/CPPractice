//
// Created by adeshchoudhar on 09/10/21.
//

class Trie {
public:
    bool is_end;
    string word;
    vector<Trie *> children;

    Trie() {
        is_end = false;
        word = "";
        children = vector<Trie *>(26, nullptr);
    }

    void insert_word(string word) {
        Trie *current = this;
        for (int i = 0; i < word.size(); i++) {
            int ind = word[i] - 'a';
            if (!current->children[ind]) {
                current->children[ind] = new Trie;
            }
            current = current->children[ind];
        }
        current->is_end = true;
        current->word = word;
    }
};

class Solution {
public:
    vector <string> findWords(vector <vector<char>> &board, vector <string> &words) {
        Trie *root = new Trie;
        for (int i = 0; i < words.size(); i++) {
            root->insert_word(words[i]);
        }

        vector <string> ans;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, ans, root, i, j);
            }
        }
        return ans;
    }

    void dfs(vector <vector<char>> &board, vector <string> &ans, Trie *root, int i, int j) {
        int m = board.size(), n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '.' || !(root->children[board[i][j] - 'a'])) {
            return;
        }

        root = root->children[board[i][j] - 'a'];
        if (root->is_end) {
            ans.push_back(root->word);
            root->is_end = false;
        }

        char c = board[i][j];
        board[i][j] = '.';
        dfs(board, ans, root, i + 1, j);
        dfs(board, ans, root, i, j + 1);
        dfs(board, ans, root, i - 1, j);
        dfs(board, ans, root, i, j - 1);
        board[i][j] = c;
    }
};
