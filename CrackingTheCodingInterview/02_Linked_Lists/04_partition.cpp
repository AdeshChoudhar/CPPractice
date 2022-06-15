//
// Problem: Write code to partition a linked list around a value x, such that
//          all nodes less than x come before all nodes greater than or equal to
//          x. If x is contained within the list, the values of x only need to
//          be after the elements less than x (see below). The partition element
//          x can appear anywhere in the "right partition"; it does not need to
//          appear between the left and right partitions.
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

void solve(Node *, int);

int main()
{
    vector<int> v = {3, 5, 8, 5, 10, 2, 1};
    LinkedList ll(v);
    int x = 5;
    cout << "INPUT(s):" << endl;
    ll.printLinkedList("\tlist = ");
    cout << "\tx = " << x << endl;

    solve(ll.head, x);

    cout << "OUTPUT(s):" << endl;
    ll.printLinkedList("\tlist = ");
    return 0;
}

void solve(Node *head, int x)
{
    Node *co = head, *cp = nullptr;
    Node *hl = new Node(0), *hm = new Node(0);
    Node *cl = hl, *cm = hm;
    while (co != nullptr)
    {
        if (co->data < x)
        {
            cl->next = co;
            cl = cl->next;
        }
        else
        {
            cm->next = co;
            cm = cm->next;
        }
        cp = co;
        co = co->next;
        cp->next = nullptr;
    }
    cl->next = hm->next;
    head = hl->next;
    delete hl;
    delete hm;
}
