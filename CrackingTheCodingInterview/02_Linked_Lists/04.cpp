//
// Problem: Write code to partition a linked list around a value x, such that
//          all nodes less than x come before all nodes greater than or equal to
//          x. If x is contained within the list, the values of x only need to
//          be after the elements less than x (see below). The partition element
//          x can appear anywhere in the "right partition"; it does not need to
//          appear between the left and right partitions.
//

#include "../../utils/utils.h"

void solve(Node<int>* head, int x) {
  Node<int>* curr = head;
  Node<int>* headl = new Node<int>(0);
  Node<int>* headh = new Node<int>(0);
  Node<int>* currl = headl;
  Node<int>* currh = headh;

  while (curr != nullptr) {
    if (curr->data < x) {
      currl->next = curr;
      currl = currl->next;
    } else {
      currh->next = curr;
      currh = currh->next;
    }
    curr = curr->next;
  }

  currh->next = nullptr;
  currl->next = headh->next;
  head = headl->next;

  delete headl;
  delete headh;
}

int main() {
  vector<int> v = {3, 5, 8, 5, 10, 2, 1};
  LinkedList<int> ll(v);
  int x = 5;

  cout << "INPUT(s):" << endl;
  printLinkedList(ll, "  ll = ");
  cout << "  x = " << x << endl;

  solve(ll.head, x);

  cout << "OUTPUT(s):" << endl;
  printLinkedList(ll, "  ll = ");

  return 0;
}
