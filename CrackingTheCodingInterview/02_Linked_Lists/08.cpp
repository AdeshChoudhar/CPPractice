//
// Problem: Given a circular linked list, implement an algorithm that returns
//          the node at the beginning of the loop.
//          DEFINITION
//          Circular linked list: A (corrupt) linked list in which a node's next
//          pointer points to an earlier node, so as to make a loop in the
//          linked list.
//

#include "../../utils/utils.h"

Node<char>* solve(Node<char>* head) {
  Node<char>* ans = nullptr;

  Node<char>* slow = head;
  Node<char>* fast = head;

  while ((fast != nullptr) && (fast->next != nullptr)) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
      ans = head;

      while (ans != slow) {
        ans = ans->next;
        slow = slow->next;
      }

      return ans;
    }
  }

  return ans;
}

int main() {
  vector<char> v = {'A', 'B', 'C', 'D', 'E'};
  LinkedList<char> ll(v);

  cout << "INPUT(s):" << endl;
  printLinkedList(ll, "  ll = ");

  ll.head->next->next->next->next->next = ll.head->next->next;

  Node<char>* ans = solve(ll.head);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << ans->data << endl;

  return 0;
}
