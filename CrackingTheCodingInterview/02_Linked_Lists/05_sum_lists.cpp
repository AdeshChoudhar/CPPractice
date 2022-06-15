//
// Problem: You have two numbers represented by a linked list, where each node
//          contains a single digit. The digits are stored in reverse order,
//          such that the 1 's digit is at the head of the list. Write a
//          function that adds the two numbers and returns the sum as a linked
//          list.
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

LinkedList solve(Node *, Node *);

int main()
{
    vector<int> n1 = {6, 1, 7}, n2 = {2, 9, 5};
    LinkedList ll1(n1), ll2(n2);
    cout << "INPUT(s):" << endl;
    ll1.printLinkedList("\tlist1 = ");
    ll2.printLinkedList("\tlist2 = ");

    LinkedList ans = solve(ll1.head, ll2.head);

    cout << "OUTPUT(s):" << endl;
    ans.printLinkedList("\tans = ");
    return 0;
}

LinkedList solve(Node *head1, Node *head2)
{
    LinkedList ans;
    vector<int> n1, n2;
    Node *c1 = head1, *c2 = head2;
    while ((c1 != nullptr) && (c2 != nullptr))
    {
        n1.push_back((c1 != nullptr) ? c1->data : 0);
        n2.push_back((c2 != nullptr) ? c2->data : 0);
        c1 = (c1 != nullptr) ? c1->next : c1;
        c2 = (c2 != nullptr) ? c2->next : c2;
    }
    int carry = 0, total;
    vector<int> res(n1.size() + 1);
    for (int i = n1.size() - 1; i >= 0; i--)
    {
        total = n1[i] + n2[i] + carry;
        res[i + 1] = total % 10;
        carry = total / 10;
    }
    res[0] = carry;
    for (int i = (int)(res[0] == 0), n = res.size(); i < n; i++)
    {
        ans.appendNode(res[i]);
    }
    return ans;
}
