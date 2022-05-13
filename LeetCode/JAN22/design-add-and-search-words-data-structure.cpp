//
// Created by adeshchoudhar on 28/01/22.
//

class WordDictionary {
public:
    bool endOfWord;
    vector<WordDictionary *> children;

    WordDictionary() {
        children.resize(26);
        for (int i = 0; i < 26; i++) {
            this->children[i] = nullptr;
        }
        endOfWord = false;
    }

    void addWord(string word) {
        int i;
        WordDictionary *currentNode = this;
        for (char w: word) {
            i = (int) (w - 'a');
            if (currentNode->children[i] == nullptr) {
                currentNode->children[i] = new WordDictionary();
            }
            currentNode = currentNode->children[i];
        }
        currentNode->endOfWord = true;
    }

    bool search(string word) {
        WordDictionary *currentNode = this;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] != '.') {
                if (!currentNode->children[word[i] - 'a']) {
                    return false;
                }
                currentNode = currentNode->children[word[i] - 'a'];
            } else {
                for (int j = 0; j < 26; j++) {
                    if (currentNode->children[j] && currentNode->children[j]->search(word.substr(i + 1))) {
                        return true;
                    }
                }
                return false;
            }
        }
        return currentNode->endOfWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
