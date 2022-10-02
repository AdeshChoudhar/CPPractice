//
// Created by adeshchoudhar on 25/9/22.
//

class MyCircularQueue {
public:
    vector<int> v;
    int idx;
    int len;

    MyCircularQueue(int k) {
        v.resize(k, -1);
        idx = 0;
        len = 0;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        v[(idx + len) % v.size()] = value;
        len += 1;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        idx = (idx + 1) % v.size();
        len -= 1;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return v[idx];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return v[(idx + len - 1) % v.size()];
    }

    bool isEmpty() {
        return (len == 0);
    }

    bool isFull() {
        return (len == v.size());
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
