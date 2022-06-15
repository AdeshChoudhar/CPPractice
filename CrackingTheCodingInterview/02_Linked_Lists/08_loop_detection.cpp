//
// Problem: Given a circular linked list, implement an algorithm that returns
//          the node at the beginning of the loop.
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

Node *solve(Node *);

int main()
{
    vector<char> v = {'A', 'B', 'C', 'D', 'E'};
    LinkedList ll(v);
    cout << "INPUT(s):" << endl;
    ll.printLinkedList("\tlist = ");
    ll.head->next->next->next->next->next = ll.head->next->next;
    cout << "\tloop = |E| is linked to |C|" << endl;

    Node *ans = solve(ll.head);

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = " << ans->data << endl;
    ll.head->next->next->next->next->next = nullptr;
    return 0;
}

Node *solve(Node *head)
{
    Node *ans, *slow = head, *fast = head;
    while ((fast != nullptr) && (fast->next != nullptr))
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
    ans = head;
    while (ans != slow)
    {
        ans = ans->next;
        slow = slow->next;
    }
    return ans;
}
