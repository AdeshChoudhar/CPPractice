class Solution
{
public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        int ans;
        Node *slow = head, *fast = head;
        while ((fast != nullptr) && (fast->next != nullptr))
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ans = slow->data;
        return ans;
    }
};
