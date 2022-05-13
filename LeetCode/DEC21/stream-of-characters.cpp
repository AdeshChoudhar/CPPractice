//
// Created by adeshchoudhar on 04/12/21.
//

class TrieNode {
public:
    TrieNode *children[26];
    bool is_end;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            this->children[i] = nullptr;
        }
        is_end = false;
    }

    void insert(string word) {
        reverse(word.begin(), word.end());
        TrieNode *current = this;
        for (char w: word) {
            if (current->children[w - 'a'] == nullptr) {
                current->children[w - 'a'] = new TrieNode();
            }
            current = current->children[w - 'a'];
        }
        current->is_end = true;
    }
};

class StreamChecker {
public:
    TrieNode root;
    vector<char> stream;
    int max_length = 0;

    StreamChecker(vector <string> &words) {
        for (string word: words) {
            root.insert(word);
            if (word.length() > max_length) {
                max_length = word.length();
            }
        }
    }

    bool query(char letter) {
        stream.push_back(letter);
        if (stream.size() > max_length) {
            stream.erase(stream.begin());
        }
        TrieNode *current = &root;
        for (int i = stream.size() - 1; i >= 0; i--) {
            if (current->is_end) {
                return true;
            }
            if (current->children[stream[i] - 'a'] == nullptr) {
                return false;
            }
            current = current->children[stream[i] - 'a'];
        }
        return current->is_end;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
