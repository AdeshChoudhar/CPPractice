//
// Created by adeshchoudhar on 08/10/21.
//

class Trie {
public:
    vector<Trie *> children;
    bool isEnd;

    Trie() {
        children = vector<Trie *>(26, nullptr);
        isEnd = false;
    }

    void insert(string word) {
        Trie *current = this;
        for (int i = 0; i < word.size(); i++) {
            int ind = (int) (word[i] - 'a');
            if (!current->children[ind]) {
                current->children[ind] = new Trie();
            }
            current = current->children[ind];
        }
        current->isEnd = true;
    }

    bool search(string word) {
        Trie *current = this;
        for (int i = 0; i < word.size(); i++) {
            int ind = (int) (word[i] - 'a');
            if (!current->children[ind]) {
                return false;
            }
            current = current->children[ind];
        }
        return current->isEnd;
    }

    bool startsWith(string prefix) {
        Trie *current = this;
        for (int i = 0; i < prefix.size(); i++) {
            int ind = (int) (prefix[i] - 'a');
            if (!current->children[ind]) {
                return false;
            }
            current = current->children[ind];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
