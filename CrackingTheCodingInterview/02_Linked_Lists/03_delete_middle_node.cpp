//
// Problem: Implement an algorithm to delete a node in the middle (i.e., any
//          node but the first and last node, not necessarily the exact middle)
//          of a singly linked list, given only access to that node.
//

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;
    Node *next;

    Node()
    {
        this->data = '\0';
        this->next = nullptr;
    }

    Node(char d)
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

    LinkedList(vector<char> &v)
    {
        this->head = nullptr;
        for (char x : v)
        {
            appendNode(x);
        }
    }

    void appendNode(char d)
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
    vector<char> v = {'a', 'b', 'c', 'd', 'e', 'f'};
    LinkedList ll(v);
    cout << "INPUT(s):" << endl;
    ll.printLinkedList("\tlist = ");

    solve(ll.head->next->next);

    cout << "OUTPUT(s):" << endl;
    ll.printLinkedList("\tlist = ");
    return 0;
}

void solve(Node *node)
{
    Node *tmp = node->next;
    node->data = tmp->data;
    node->next = tmp->next;
    tmp->next = nullptr;
    delete tmp;
}
