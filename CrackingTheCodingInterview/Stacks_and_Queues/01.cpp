//
// Problem: Describe how you could use a single array to implement three stacks.
//

#include "../../utils/utils.h"

class kNode {
public:
  int data;
  kNode* next;

  kNode(int data) {
    this->data = data;
    this->next = nullptr;
  }
};

class kStacks {
private:
  // main array to store elements
  int kth;
  int cap;
  vector<kNode*> arr;

public:
  kStacks(int n, int k) : kth(k), cap(n) {
    // initialize data structures for k stacks
    this->arr.resize(this->kth);
    for (int i = 0; i < this->kth; i++) {
      this->arr[i] = new kNode(-1);
    }
  }

  void push(int x, int i) {
    // push element x into stack i
    if ((i < 0) || (i >= this->kth) || (this->cap == 0)) {
      return;
    }

    kNode* head = this->arr[i];
    kNode* node = new kNode(x);
    node->next = head->next;
    head->next = node;

    this->cap += 1;
  }

  int pop(int i) {
    // pop element from stack i
    int res = -1;

    if ((i < 0) || (i >= this->kth)) {
      return res;
    }

    kNode* head = this->arr[i];

    if (head->next == nullptr) {
      return res;
    }

    kNode* node = head->next;
    head->next = node->next;
    node->next = nullptr;

    res = node->data;

    delete node;

    this->cap -= 1;

    return res;
  }

  ~kStacks() {
    for (int i = 0; i < this->kth; i++) {
      kNode* curr = this->arr[i];
      while (curr != nullptr) {
        kNode* next = curr->next;
        delete curr;
        curr = next;
      }
    }
  }
};

int main() {
  int n = 9;
  int k = 3;

  kStacks stk(n, k);

  vector<vector<int>> queries = {
      {1, 2, 0},
      {1, 5, 0},
      {1, 4, 1},
      {2, 1},
      {1, 3, 2},
      {2, 0},
      {2, 0},
  };

  cout << "INPUT(s):" << endl;
  cout << "  n = " << n << endl;
  cout << "  k = " << k << endl;
  printMatrix(queries, "  queries = ");

  vector<int> ans;

  for (auto query : queries) {
    if (query[0] == 1) {
      stk.push(query[1], query[2]);
    } else {
      ans.push_back(stk.pop(query[1]));
    }
  }

  cout << "OUTPUT(s):" << endl;
  printVector(ans, "  ans = ");

  return 0;
}
