//
// Problem: Implement a MyQueue class which implements a queue using two stacks.
//

#include "../../utils/utils.h"

template <typename T>
class MyQueue {
private:
  stack<T> s1;
  stack<T> s2;

public:
  MyQueue() {}

  void push(T data) {
    this->s1.push(data);
  }

  void pop() {
    if (this->s2.empty()) {
      update();
    }

    this->s2.pop();
  }

  optional<T> front() {
    T res;

    if (this->s2.empty()) {
      update();
    }

    if (this->s2.empty()) {
      return nullopt;
    }

    res = this->s2.top();

    return res;
  }

  int size() {
    return (int)(this->s1.size() + this->s2.size());
  }

  void update() {
    while (!this->s1.empty()) {
      this->s2.push(this->s1.top());
      this->s1.pop();
    }
  }
};

int main() {
  MyQueue<int> que;

  vector<vector<int>> queries = {
      {1, 5},
      {1, 3},
      {1, 4},
      {3},
      {2},
      {4},
      {3},
  };

  cout << "INPUT(s):" << endl;
  printMatrix(queries, "  queries = ");

  vector<int> ans;

  for (auto query : queries) {
    if (query[0] == 1) {
      que.push(query[1]);
    } else if (query[0] == 2) {
      que.pop();
    } else if (query[0] == 3) {
      ans.push_back(que.front().value_or(-1));
    } else if (query[0] == 4) {
      ans.push_back(que.size());
    }
  }

  cout << "OUTPUT(s):" << endl;
  printVector(ans, "  ans = ");

  return 0;
}
