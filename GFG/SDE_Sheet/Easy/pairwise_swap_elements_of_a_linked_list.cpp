class Solution
{
public:
    Node *pairWiseSwap(struct Node *head)
    {
        Node *ans = head;
        if ((head == nullptr) || (head->next == nullptr))
        {
            return ans;
        }
        ans = head->next;
        head->next = pairWiseSwap(head->next->next);
        ans->next = head;
        return ans;
    }
};
