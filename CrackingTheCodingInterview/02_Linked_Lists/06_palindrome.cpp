//
// Problem: Implement a function to check if a linked list is a palindrome.
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

bool solve(Node *);

int main()
{
    vector<int> v = {1, 2, 3, 2, 1};
    LinkedList ll(v);
    cout << "INPUT(s):" << endl;
    ll.printLinkedList("\tlist = ");

    bool ans = solve(ll.head);

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = " << ans << endl;
    return 0;
}

bool solve(Node *head)
{
    bool ans = true;
    if (head == nullptr || head->next == nullptr)
    {
        return ans;
    }
    Node *slow = head, *fast = head, *rev = nullptr, *pre;
    while ((fast != nullptr) && (fast->next != nullptr))
    {
        pre = rev;
        rev = slow;
        slow = slow->next;
        fast = fast->next->next;
        rev->next = pre;
    }
    Node *org = (fast != nullptr) ? slow->next : slow;
    while (org != nullptr)
    {
        if (org->data != rev->data)
        {
            ans = false;
        }
        pre = slow;
        slow = rev;
        org = org->next;
        rev = rev->next;
        slow->next = pre;
    }
    return ans;
}
