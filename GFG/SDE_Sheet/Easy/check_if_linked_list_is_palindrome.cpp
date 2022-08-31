class Solution
{
public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        bool ans = true;
        Node *slow = head, *fast = head;
        if ((head == nullptr) || (head->next == nullptr))
        {
            return ans;
        }
        while ((fast->next != nullptr) && (fast->next->next != nullptr))
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = reverseList(slow->next);
        slow = head;
        while ((fast != nullptr) && ans)
        {
            if (slow->data != fast->data)
            {
                ans = false;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return ans;
    }

    Node *reverseList(Node *head)
    {
        Node *prev = nullptr, *curr = head, *next = nullptr;
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
