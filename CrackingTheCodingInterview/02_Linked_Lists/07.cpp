//
// Problem: Given two (singly) linked lists, determine if the two lists
//          intersect. Return the inter­secting node. Note that the intersection
//          is defined based on reference, not value. That is, if the kth node
//          of the first linked list is the exact same node (by reference) as
//          the jth node of the second linked list, then they are intersecting.
//

#include "../../utils/utils.h"

Node<int>* solve(Node<int>* head1, Node<int>* head2) {
  Node<int>* ans = nullptr;

  Node<int>* curr1 = head1;
  Node<int>* curr2 = head2;

  int len1 = 0, len2 = 0;

  for (; curr1 != nullptr; curr1 = curr1->next) {
    len1 += 1;
  }

  for (; curr2 != nullptr; curr2 = curr2->next) {
    len2 += 1;
  }

  curr1 = head1;
  curr2 = head2;

  if (len1 < len2) {
    for (int i = 0; i < (len2 - len1); i++) {
      curr2 = curr2->next;
    }
  } else {
    for (int i = 0; i < (len1 - len2); i++) {
      curr1 = curr1->next;
    }
  }

  while (curr1 != curr2) {
    curr1 = curr1->next;
    curr2 = curr2->next;
  }

  ans = curr1;

  return ans;
}

int main() {
  vector<int> v1 = {1, 2, 3, 4};
  vector<int> v2 = {5, 6, 7};
  vector<int> v3 = {8, 9, 10};

  LinkedList<int> ll1(v1);
  LinkedList<int> ll2(v2);
  LinkedList<int> ll3(v3);

  ll1.head->next->next->next->next = ll3.head;
  ll2.head->next->next->next = ll3.head;

  cout << "INPUT(s):" << endl;
  printLinkedList(ll1, "  list1 = ");
  printLinkedList(ll2, "  list2 = ");

  Node<int>* ans = solve(ll1.head, ll2.head);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << ans->data << endl;

  return 0;
}
