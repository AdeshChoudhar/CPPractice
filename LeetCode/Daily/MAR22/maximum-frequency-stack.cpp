//
// Created by adeshchoudhar on 19/03/22.
//

class FreqStack {
public:
    int mf = 0;
    unordered_map<int, int> fq;
    unordered_map<int, stack<int>> st;

    FreqStack() {

    }

    void push(int val) {
        mf = max(mf, ++fq[val]);
        st[fq[val]].push(val);
    }

    int pop() {
        int val = st[mf].top();
        st[mf].pop();
        if (!st[fq[val]--].size()) {
            mf -= 1;
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
