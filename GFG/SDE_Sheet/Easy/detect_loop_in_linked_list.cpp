class Solution
{
public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node *head)
    {
        bool ans = false;
        Node *slow = head, *fast = head;
        while ((fast != nullptr) && (fast->next != nullptr) && !ans)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                ans = true;
            }
        }
        return ans;
    }
};
