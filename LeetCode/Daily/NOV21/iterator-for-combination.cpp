//
// Created by adeshchoudhar on 14/11/21.
//

class CombinationIterator {
public:
    set <string> combinations;
    set<string>::iterator current;

    CombinationIterator(string characters, int combinationLength) {
        this->combinations = pre(characters, combinationLength);
        this->current = this->combinations.begin();
    }

    string next() {
        string nextCombination = *(this->current);
        this->current++;
        return nextCombination;
    }

    bool hasNext() {
        return (this->current != this->combinations.end());
    }

    set <string> pre(string s, int len) {
        int mask = 1 << s.length();
        set <string> combinations;
        string tmp = "";
        for (int m = 1; m < mask; m++) {
            int num = m;
            int i = 0;
            while (num) {
                if (num & 1) {
                    tmp = tmp + s[i];
                }
                i += 1;
                num >>= 1;
            }
            if (tmp.length() == len) {
                combinations.insert(tmp);
            }
            tmp = "";
        }
        return combinations;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
