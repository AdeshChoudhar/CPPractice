//
// Problem: Implement an algorithm to delete a node in the middle (i.e., any
//          node but the first and last node, not necessarily the exact middle)
//          of a singly linked list, given only access to that node.
//

#include "../../utils/utils.h"

void solve(LinkedList<char>& ll, Node<char>* node) {
  if ((ll.head == nullptr) || (node == nullptr)) {
    return;
  }

  Node<char>* curr = ll.head;
  Node<char>* prev = nullptr;

  while (curr->data != node->data) {
    prev = curr;
    curr = curr->next;
  }

  if (prev == nullptr) {
    ll.head = curr->next;
  } else {
    prev->next = curr->next;
  }

  curr->next = nullptr;
  delete curr;
}

int main() {
  vector<char> v = {'a', 'b', 'c', 'd', 'e', 'f'};
  LinkedList<char> ll(v);

  cout << "INPUT(s):" << endl;
  printLinkedList(ll, "  ll = ");

  solve(ll, ll.head->next->next->next);

  cout << "OUTPUT(s):" << endl;
  printLinkedList(ll, "  ll = ");

  return 0;
}
