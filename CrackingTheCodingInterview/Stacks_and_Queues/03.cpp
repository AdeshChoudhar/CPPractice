//
// Problem: Imagine a (literal) stack of plates. If the stack gets too high, it
//          might topple. Therefore, in real life, we would likely start a new
//          stack when the previous stack exceeds some threshold. Implement a
//          data structure SetOfStacks that mimics this. SetOfStacks should be
//          composed of several stacks and should create a new stack once the
//          previous one exceeds capacity. SetOfStacks.push() and
//          SetOfStacks.pop() should behave identically to a single stack (that
//          is, pop() should return the same values as it would if there were
//          just a single stack).
//          FOLLOW UP
//          Implement a function popAt(int index) which performs a pop operation
//          on a specific sub-stack.
//

#include "../../utils/utils.h"

template <typename T>
class SetOfStacks {
private:
  size_t cap;
  vector<stack<T>> stk;

public:
  SetOfStacks(int cap) : cap((size_t)cap) {}

  void push(T data) {
    if (this->stk.empty() || (this->stk.back().size() == this->cap)) {
      this->stk.push_back(stack<T>());
    }

    this->stk.back().push(data);
  }

  void pop() {
    if (this->stk.empty()) {
      return;
    }

    while (!this->stk.empty() && this->stk.back().empty()) {
      this->stk.pop_back();
    }

    this->stk.back().pop();

    while (!this->stk.empty() && this->stk.back().empty()) {
      this->stk.pop_back();
    }
  }

  optional<T> top() {
    T res;

    if (this->stk.empty()) {
      return nullopt;
    }

    res = this->stk.back().top();

    return res;
  }

  void popAt(int idx) {
    if (((idx > 0) && (idx >= (int)this->stk.size())) ||
        this->stk[idx].empty()) {
      return;
    }

    this->stk[idx].pop();

    while (!this->stk.empty() && this->stk.back().empty()) {
      this->stk.pop_back();
    }
  }
};

int main() {
  SetOfStacks<int> stk(2);

  vector<vector<string>> ops = {
      {"push", "1"},
      {"push", "2"},
      {"push", "3"},
      {"pop"},
      {"top"},
      {"push", "4"},
      {"push", "5"},
      {"push", "6"},
      {"push", "7"},
      {"pop"},
      {"top"},
      {"popAt", "1"},
      {"top"},
      {"pop"},
      {"top"},
      {"popAt", "0"},
      {"popAt", "0"},
      {"top"},
      {"pop"},
      {"top"},
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
    } else if (op[0] == "popAt") {
      stk.popAt(stoi(op[1]));
      ans.push_back("null");
    }
  }

  cout << "INPUT(s):" << endl;
  printVector(ans, " ans = ");

  return 0;
}
