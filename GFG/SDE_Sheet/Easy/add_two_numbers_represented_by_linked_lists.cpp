class Solution
{
public:
    // Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        struct Node *ans = new struct Node(-1);
        first = reverseList(first);
        second = reverseList(second);
        int x, c = 0;
        struct Node *a = ans, *f = first, *s = second;
        while ((f != nullptr) && (s != nullptr))
        {
            x = f->data + s->data + c;
            c = x / 10;
            a->next = new struct Node(x % 10);
            a = a->next;
            f = f->next;
            s = s->next;
        }
        while (f != nullptr)
        {
            x = f->data + c;
            c = x / 10;
            a->next = new struct Node(x % 10);
            a = a->next;
            f = f->next;
        }
        while (s != nullptr)
        {
            x = s->data + c;
            c = x / 10;
            a->next = new struct Node(x % 10);
            a = a->next;
            s = s->next;
        }
        if (c != 0)
        {
            a->next = new struct Node(c);
            a = a->next;
        }
        struct Node *tmp = ans;
        ans = reverseList(ans->next);
        tmp->next = nullptr;
        delete tmp;
        return ans;
    }

    struct Node *reverseList(struct Node *head)
    {
        struct Node *prev = nullptr, *curr = head, *next = nullptr;
        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
