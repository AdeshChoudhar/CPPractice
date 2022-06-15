//
// Problem: Implement an algorithm to find the kth to last element of a singly
//          linked list.
//

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = nullptr;
    }

    Node(int d)
    {
        this->data = d;
        this->next = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        this->head = nullptr;
    }

    LinkedList(vector<int> &v)
    {
        this->head = nullptr;
        for (int x : v)
        {
            appendNode(x);
        }
    }

    void appendNode(int d)
    {
        Node *node = new Node(d);
        if (this->head == nullptr)
        {
            head = node;
            return;
        }
        Node *current = this->head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = node;
    }

    void printLinkedList(string s)
    {
        cout << s;
        Node *current = this->head;
        while (current != nullptr)
        {
            cout << "|" << current->data << "|->";
            current = current->next;
        }
        cout << "|nullptr|" << endl;
    }

    ~LinkedList()
    {
        Node *current = this->head, *previous = nullptr;
        while (current != nullptr)
        {
            previous = current;
            current = current->next;
            previous->next = nullptr;
            delete previous;
        }
    }
};

Node *solve(Node *, int);

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    LinkedList ll(v);
    int k = 3;
    cout << "INPUT(s):" << endl;
    ll.printLinkedList("\tlist = ");
    cout << "\tk = " << k << endl;

    Node *ans = solve(ll.head, k);

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = " << (ans ? to_string(ans->data) : "nullptr") << endl;
    return 0;
}

Node *solve(Node *head, int k)
{
    Node *ans = nullptr, *current = head;
    while ((current != nullptr) && (k > 0))
    {
        current = current->next;
        k -= 1;
    }
    if (k == 0)
    {
        ans = head;
        while (current != nullptr)
        {
            ans = ans->next;
            current = current->next;
        }
    }
    return ans;
}
