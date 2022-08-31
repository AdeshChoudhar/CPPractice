class Solution
{
public:
    // Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del)
    {
        Node *tmp = del->next;
        del->data = tmp->data;
        del->next = tmp->next;
        tmp->next = nullptr;
        delete tmp;
    }
};
