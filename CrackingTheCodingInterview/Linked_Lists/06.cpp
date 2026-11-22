//
// Problem: Implement a function to check if a linked list is a palindrome.
//

#include "../../utils/utils.h"

bool solve(Node<int>* head) {
  bool ans = true;

  if ((head == nullptr) || (head->next == nullptr)) {
    return ans;
  }

  Node<int>* slow = head;
  Node<int>* fast = head;

  deque<int> deq;
  deque<int> qed;

  while ((fast != nullptr) && (fast->next != nullptr)) {
    slow = slow->next;
    fast = fast->next->next;
  }

  if (fast != nullptr) {
    slow = slow->next;
  }

  fast = head;

  while (slow != nullptr) {
    deq.push_back(slow->data);
    qed.push_front(fast->data);
    slow = slow->next;
    fast = fast->next;
  }

  ans = (deq == qed);

  return ans;
}

int main() {
  vector<int> v = {1, 2, 2, 1};
  LinkedList ll(v);

  cout << "INPUT(s):" << endl;
  printLinkedList(ll, " list = ");

  bool ans = solve(ll.head);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << (ans ? "true" : "false") << endl;

  return 0;
}
