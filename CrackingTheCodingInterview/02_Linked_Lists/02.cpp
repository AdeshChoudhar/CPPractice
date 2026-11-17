//
// Problem: Implement an algorithm to find the kth to last element of a singly
//          linked list.
//

#include "../../utils/utils.h"

Node<int>* solve(Node<int>* head, int k) {
  Node<int>* ans = nullptr;
  
  int cnt = 0;
  
  Node<int>* curr = head;

  while (curr != nullptr) {
    cnt += 1;
    curr = curr->next;
  }

  if ((cnt - k) < 0) {
    return ans;
  }

  ans = head;

  for (int i = 0; (ans != nullptr) && (i < (cnt - k)); i++) {
    ans = ans->next;
  }

  return ans;
}

int main() {
  vector<int> v = {1, 2, 3, 4, 5};
  LinkedList<int> ll(v);
  int k = 5;

  cout << "INPUT(s):" << endl;
  printLinkedList(ll, "  ll = ");
  cout << "  k = " << k << endl;

  Node<int>* ans = solve(ll.head, k);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << (ans ? to_string(ans->data) : "null") << endl;

  return 0;
}
