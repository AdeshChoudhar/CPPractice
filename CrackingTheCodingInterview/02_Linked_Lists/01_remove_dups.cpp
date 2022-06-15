//
// Problem: Write code to remove duplicates from an unsorted linked list.
//          FOLLOW UP
//          How would you solve this problem if a temporary buffer is not
//          allowed?
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

void solve(Node *);

int main()
{
    vector<int> v = {1, 2, 2, 3, 1, 3};
    LinkedList ll(v);
    cout << "INPUT(s):" << endl;
    ll.printLinkedList("\tlist = ");

    solve(ll.head);

    cout << "OUTPUT(s):" << endl;
    ll.printLinkedList("\tlist = ");
    return 0;
}

void solve(Node *head)
{
    Node *current1 = head;
    while (current1 != nullptr)
    {
        Node *current2 = current1->next, *previous = current1;
        while (current2 != nullptr)
        {
            if (current2->data == current1->data)
            {
                previous->next = current2->next;
                current2->next = nullptr;
                delete current2;
                current2 = previous;
            }
            previous = current2;
            current2 = current2->next;
        }
        current1 = current1->next;
    }
}
