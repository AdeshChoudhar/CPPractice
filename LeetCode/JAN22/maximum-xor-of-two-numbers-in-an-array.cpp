//
// Created by adeshchoudhar on 28/01/22.
//

class TrieNode {
public:
    TrieNode *children[2];

    TrieNode() {
        this->children[0] = nullptr;
        this->children[1] = nullptr;
    }

    void trieInsert(int n) {
        bitset<32> bs(n);
        TrieNode *currentNode = this;
        for (int i = 31; i >= 0; i--) {
            if (currentNode->children[bs[i]] == nullptr) {
                currentNode->children[bs[i]] = new TrieNode();
            }
            currentNode = currentNode->children[bs[i]];
        }
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int> &nums) {
        TrieNode *root = new TrieNode();
        for (int num: nums) {
            root->trieInsert(num);
        }
        int ans = 0;
        for (int num: nums) {
            ans = max(ans, findMaximumXORUtil(root, num));
        }
        return ans;
    }

    int findMaximumXORUtil(TrieNode *root, int n) {
        int res = 0;
        bitset<32> bs(n);
        TrieNode *currentNode = root;
        for (int i = 31; i >= 0; i--) {
            if (currentNode->children[!bs[i]]) {
                res += (1 << i);
                currentNode = currentNode->children[!bs[i]];
            } else {
                currentNode = currentNode->children[bs[i]];
            }
        }
        return res;
    }
};
