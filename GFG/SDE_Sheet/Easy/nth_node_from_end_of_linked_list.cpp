int getNthFromLast(Node *head, int n)
{
    int ans = -1, len = 0;
    Node *curr = head;
    while (curr != nullptr)
    {
        len += 1;
        curr = curr->next;
    }
    if (n > len)
    {
        return ans;
    }
    curr = head;
    for (int i = 0; i < (len - n); i++)
    {
        curr = curr->next;
    }
    ans = (curr != nullptr) ? curr->data : ans;
    return ans;
}
