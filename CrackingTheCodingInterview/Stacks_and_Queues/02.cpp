//
// Problem: How would you design a stack which, in addition to push and pop, has
//          a function min which returns the minimum element? Push, pop and min
//          should all operate in O(1) time.
//

#include "../../utils/utils.h"

template <typename T>
class MinStack {
public:
  LinkedList<T> ll;
  LinkedList<T> mn;

  MinStack() {}

  void push(T data) {
    Node<T>* node = new Node(data);

    node->next = this->ll.head;
    this->ll.head = node;

    if ((this->mn.head == nullptr) || (this->mn.head->data >= data)) {
      Node<T>* mnode = new Node(data);
      mnode->next = this->mn.head;
      this->mn.head = mnode;
    }
  }

  void pop() {
    if (this->ll.head == nullptr) {
      return;
    }

    if (this->ll.head->data == this->mn.head->data) {
      Node<int>* mnode = this->mn.head;
      this->mn.head = this->mn.head->next;
      mnode->next = nullptr;
      delete mnode;
    }

    Node<int>* node = this->ll.head;
    this->ll.head = this->ll.head->next;
    node->next = nullptr;
    delete node;
  }

  optional<T> top() {
    T res;

    if (this->ll.head == nullptr) {
      return nullopt;
    }

    res = this->ll.head->data;

    return res;
  }

  optional<T> getMin() {
    T res;

    if (this->mn.head == nullptr) {
      return nullopt;
    }

    res = this->mn.head->data;

    return res;
  }

  ~MinStack() {
    while (this->ll.head != nullptr) {
      pop();
    }
  }
};

int main() {
  MinStack<int> stk;

  vector<vector<string>> ops = {
      {"push", "-2"},
      {"push", "0"},
      {"push", "-3"},
      {"getMin"},
      {"pop"},
      {"top"},
      {"getMin"},
  };

  cout << "INPUT(s):" << endl;
  printMatrix(ops, "  ops = ");

  vector<string> ans;

  for (auto op : ops) {
    if (op[0] == "push") {
      stk.push(stoi(op[1]));
      ans.push_back("null");
    } else if (op[0] == "pop") {
      stk.pop();
      ans.push_back("null");
    } else if (op[0] == "top") {
      ans.push_back(to_string(stk.top().value_or(-1)));
    } else if (op[0] == "getMin") {
      ans.push_back(to_string(stk.getMin().value_or(-1)));
    }
  }

  cout << "INPUT(s):" << endl;
  printVector(ans, " ans = ");

  return 0;
}
