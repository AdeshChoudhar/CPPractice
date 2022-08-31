//
// Created by adeshchoudhar on 21/04/22.
//

class MyHashSet {
public:
    const static int MAX = (int) (1e6 + 1);
    bitset <MAX> b;

    MyHashSet() {
    }

    void add(int key) {
        b[key] = true;
    }

    void remove(int key) {
        b[key] = false;
    }

    bool contains(int key) {
        return b[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
