//
// Problem: Given two (singly) linked lists, determine if the two lists
//          intersect. Return the inter­secting node. Note that the intersection
//          is defined based on reference, not value.That is, if the kth node of
//          the first linked list is the exact same node (by reference) as the
//          jth node of the second linked list, then they are intersecting.
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

Node *solve(Node *, Node *);

int main()
{
    vector<int> v1 = {1, 2, 3, 4, 5}, v2 = {1, 2, 3};
    LinkedList ll1(v1), ll2(v2);
    cout << "INPUT(s):" << endl;
    ll1.printLinkedList("\tlist1 = ");
    ll2.printLinkedList("\tlist2 = ");
    ll2.head->next->next->next = ll1.head->next->next->next;
    cout << "\tmerge = |3| of list2 is linked to |4| of list1" << endl;

    Node *ans = solve(ll1.head, ll2.head);

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = " << ans->data << endl;
    ll2.head->next->next->next = nullptr;
    return 0;
}

Node *solve(Node *head1, Node *head2)
{
    Node *ans, *c1 = head1, *c2 = head2;
    int l1 = 0, l2 = 0;
    while (c1 != nullptr)
    {
        l1 += 1;
        c1 = c1->next;
    }
    while (c2 != nullptr)
    {
        l2 += 1;
        c2 = c2->next;
    }
    c1 = head1, c2 = head2;
    if (l1 < l2)
    {
        for (int i = 0; i < (l2 - l1); i++)
        {
            c2 = c2->next;
        }
    }
    else
    {
        for (int i = 0; i < (l1 - l2); i++)
        {
            c1 = c1->next;
        }
    }
    while (c1 != c2)
    {
        c1 = c1->next;
        c2 = c2->next;
    }
    ans = c1;
    return ans;
}
