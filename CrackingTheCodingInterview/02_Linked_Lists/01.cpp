//
// Problem: Write code to remove duplicates from an unsorted linked list.
//          FOLLOW UP
//          How would you solve this problem if a temporary buffer is not
//          allowed?
//

#include "../../utils/utils.h"

void solve(Node<int>* head) {
  Node<int>* curr1 = head;

  while (curr1 != nullptr) {
    Node<int>* curr2 = curr1->next;
    Node<int>* prev = curr1;

    while (curr2 != nullptr) {
      if (curr2->data == curr1->data) {
        prev->next = curr2->next;
        curr2->next = nullptr;
        delete curr2;
        curr2 = prev;
      }

      prev = curr2;
      curr2 = curr2->next;
    }

    curr1 = curr1->next;
  }
}

int main() {
  vector<int> v = {1, 2, 2, 3, 1, 3};
  LinkedList<int> ll(v);

  cout << "INPUT(s):" << endl;
  printLinkedList(ll, "  ll = ");

  solve(ll.head);

  cout << "OUTPUT(s):" << endl;
  printLinkedList(ll, "  ll = ");

  return 0;
}
