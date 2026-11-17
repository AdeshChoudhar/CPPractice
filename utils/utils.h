#include <bits/stdc++.h>

#include "linked_list.h"

using namespace std;

// Function to print a vector of any type T
template <typename T>
void printVector(vector<T>& vec, string str = "") {
  if (!str.empty()) {
    cout << str;
  }

  cout << "{ ";

  if (vec.empty()) {
    cout << "}" << endl;
    return;
  }

  cout << vec.front();

  for (int i = 1, n = vec.size(); i < n; i++) {
    cout << ", " << vec[i];
  }

  cout << " }" << endl;
}

// Function to print a matrix of any type T
template <typename T>
void printMatrix(vector<vector<T>>& mat, string str = "") {
  if (!str.empty()) {
    cout << str;
  }

  cout << "{" << endl;

  int len = str.length();
  string spaces(len, ' ');

  for (int i = 0, n = mat.size(); i < n; i++) {
    printVector<T>(mat[i], spaces + "  ");
  }

  cout << spaces << "}" << endl;
}

// Function to print a linked list of any type T
template <typename T>
void printLinkedList(LinkedList<T>& ll, string str = "") {
  if (!str.empty()) {
    cout << str;
  }

  Node<T>* curr = ll.head;

  while (curr != nullptr) {
    cout << "|" << curr->data << "|->";
    curr = curr->next;
  }

  cout << "|null|" << endl;
}
