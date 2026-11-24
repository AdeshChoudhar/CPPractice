//
// Problem: Write a program to sort a stack such that the smallest items are on
//          the top. You can use an additional temporary stack, but you may not
//          copy the elements into any other data structure (such as an array).
//          The stack supports the following operations: push, pop, peek, and
//          isEmpty.
//

#include "../../utils/utils.h"

template <typename T>
class MyStack {
private:
  stack<T> stk;
  stack<T> tmp;

public:
  MyStack(vector<T> vec) {
    if (vec.empty()) {
      return;
    }

    for (auto ele : vec) {
      this->stk.push(ele);
    }

    this->sort();
  }

  void push(T data) {
    while (!this->isEmpty() && (this->peek() > data)) {
      this->tmp.push(this->peek().value());
      this->pop();
    }

    this->stk.push(data);

    while (!this->tmp.empty()) {
      this->stk.push(tmp.top());
      tmp.pop();
    }
  }

  void pop() {
    this->stk.pop();
  }

  optional<T> peek() {
    T res;

    if (this->stk.empty()) {
      return nullopt;
    }

    res = this->stk.top();

    return res;
  }

  bool isEmpty() {
    return this->stk.empty();
  }

  void sort() {
    for (int i = 0, n = this->stk.size(); i < n; i++) {
      T mxm = this->peek().value();
      this->pop();

      for (int j = 0; j < (n - i - 1); j++) {
        T top = this->peek().value();
        this->pop();

        if (top > mxm) {
          this->tmp.push(mxm);
          mxm = top;
        } else {
          this->tmp.push(top);
        }
      }

      this->stk.push(mxm);

      while (!tmp.empty()) {
        this->stk.push(tmp.top());
        tmp.pop();
      }
    }
  }
};

int main() {
  vector<int> vec = {41, 3, 32, 2, 11};
  MyStack<int> stk(vec);

  cout << "INPUT(s):" << endl;
  printVector(vec, "vec = ");

  vector<int> ans;

  while (!stk.isEmpty()) {
    ans.push_back(stk.peek().value_or(-1));
    stk.pop();
  }

  cout << "OUTPUT(s):" << endl;
  printVector(ans, "  ans = ");

  return 0;
}
