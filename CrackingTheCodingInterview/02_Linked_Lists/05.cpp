//
// Problem: You have two numbers represented by a linked list, where each node
//          contains a single digit. The digits are stored in reverse order,
//          such that the 1 's digit is at the head of the list. Write a
//          function that adds the two numbers and returns the sum as a linked
//          list.
//          FOLLOW UP
//          Suppose the digits are stored in forward order. Repeat the above
//          problem.
//

#include "../../utils/utils.h"

LinkedList<int> solve(Node<int>* head1, Node<int>* head2) {
  LinkedList<int> ans;

  vector<int> v1;
  vector<int> v2;

  Node<int>* curr1 = head1;
  Node<int>* curr2 = head2;

  while (curr1 != nullptr) {
    v1.push_back(curr1->data);
    curr1 = curr1->next;
  }

  while (curr2 != nullptr) {
    v2.push_back(curr2->data);
    curr2 = curr2->next;
  }

  vector<int> v;
  int cry = 0, sum;

  while (!v1.empty() && !v2.empty()) {
    sum = v1.back() + v2.back() + cry;
    v.push_back(sum % 10);
    cry = sum / 10;
    v1.pop_back();
    v2.pop_back();
  }

  while (!v1.empty()) {
    sum = v1.back() + cry;
    v.push_back(sum % 10);
    cry = sum / 10;
    v1.pop_back();
  }

  while (!v2.empty()) {
    sum = v2.back() + cry;
    v.push_back(sum % 10);
    cry = sum / 10;
    v2.pop_back();
  }

  if (cry > 0) {
    v.push_back(cry);
  }

  while (v.size() > 1 && v.back() == 0) {
    v.pop_back();
  }

  reverse(v.begin(), v.end());

  ans = LinkedList<int>(v);

  return ans;
}

int main() {
  vector<int> n1 = {6, 1, 7};
  vector<int> n2 = {2, 9, 5};

  LinkedList<int> ll1(n1);
  LinkedList<int> ll2(n2);

  cout << "INPUT(s):" << endl;
  printLinkedList(ll1, "  list1 = ");
  printLinkedList(ll2, "  list2 = ");

  LinkedList<int> ans = solve(ll1.head, ll2.head);

  cout << "OUTPUT(s):" << endl;
  printLinkedList(ans, "  ans = ");

  return 0;
}
