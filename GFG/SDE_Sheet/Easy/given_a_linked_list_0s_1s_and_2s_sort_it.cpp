class Solution
{
public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node *segregate(Node *head)
    {
        Node *ans;
        Node *zero = new Node(-1), *one = new Node(-1), *two = new Node(-1);
        Node *ch = head, *c0 = zero, *c1 = one, *c2 = two;
        while (ch != nullptr)
        {
            if (ch->data == 0)
            {
                c0->next = ch;
                c0 = c0->next;
            }
            else if (ch->data == 1)
            {
                c1->next = ch;
                c1 = c1->next;
            }
            else
            {
                c2->next = ch;
                c2 = c2->next;
            }
            ch = ch->next;
        }
        c2->next = nullptr;
        c1->next = two->next;
        c0->next = one->next;
        ans = zero->next;
        delete zero;
        delete one;
        delete two;
        return ans;
    }
};
