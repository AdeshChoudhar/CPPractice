class Solution
{
public:
    // Function to reverse a linked list.
    struct Node *reverseList(struct Node *head)
    {
        struct Node *ans, *prev = nullptr, *curr = head, *next = nullptr;
        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ans = prev;
        return ans;
    }
};
